#include "databasemanager.h"
#include <QDir>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

DatabaseManager::DatabaseManager(QObject *parent) :
    QObject(parent)
{
}

bool DatabaseManager::openDB()
{
    bool dbExists = true;

    // Find QSLite driver
    db = QSqlDatabase::addDatabase("QSQLITE");

    // NOTE: We have to store database file into user home folder in Linux
    QString path(QDir::home().path());
    path.append(QDir::separator()).append("taEval.db.sqlite");
    path = QDir::toNativeSeparators(path);

    QFile fOut(path);

    if(!fOut.exists())
    {
        // if the database does not exist populate it with the default records
        dbExists = false;
    }
    db.setDatabaseName(path);

    // Open database
    bool dbOpened =  db.open();

    if(!dbExists)
    {
        buildDB();
        populateDB();
    }

    // Open database
    return dbOpened;
}

QSqlError DatabaseManager::lastError()
{
    // If opening database has failed user can ask
    // error description by QSqlError::text()
    return db.lastError();
}

void DatabaseManager::printLastError(QString errName, QString databaseText, QString driverText)
{
    qDebug() << errName << " error";
    qDebug() << "Database Text: " << databaseText;
    qDebug() << "Driver Text: " << driverText;
}

bool DatabaseManager::deleteDB()
{
    // Close database
    db.close();

    #ifdef Q_OS_LINUX
    // NOTE: We have to store database file into user home folder in Linux
    QString path(QDir::home().path());
    path.append(QDir::separator()).append("taEval.db.sqlite");
    path = QDir::toNativeSeparators(path);
    return QFile::remove(path);
    #else

    // Remove created database binary file
    return QFile::remove("taEval.db.sqlite");
    #endif
}


bool DatabaseManager::buildDB()
{
    // Create the tables for the database
    DatabaseManager::createTATable();
    DatabaseManager::createInstructorTable();
    DatabaseManager::createCourseTable();
    DatabaseManager::createTaskTable();
    DatabaseManager::createEvaluationTable();
    DatabaseManager::createInstructorCoursesTable();
    DatabaseManager::createCourseTAsTable();

    return true;
}


void DatabaseManager::populateDB()
{
    // insert some TAs
    insertTA("Mary Sue", "mary.sue@carleton.ca", qreal(4.0), qint32(100869040));
    insertTA("Joe Quimby", "joe.quimby@carleton.ca", qreal(4.0), qint32(100869039));
    insertTA("Monty Burns", "monty.burns@carleton.ca", qreal(4.0), qint32(100869038));


    insertInstructor("Joe Teacher", "joeteach@carleton.ca", "CS", "HP5120");

    insertCourse("Software Engineering", "COMP3004", "F2013", "Design some sofware.", "Tuesday");
    insertCourse("Programming Paradigms", "COMP3007", "F2013", "Learn about programming languages.", "Wednesday");
    insertCourse("Intro to Computer Science", "COMP1405", "F2013", "Learn some basic computery things.", "Friday");
    insertCourse("Systems Programming", "COMP2401", "F2013", "Do some low level things.", "Monday");
    insertCourse("Discrete Mathematics", "COMP1805", "F2013", "Logic and proofs.", "Thursday");

    insertCourseTARelationship(1, 1);
    insertCourseTARelationship(1, 2);
    insertCourseTARelationship(1, 3);


    insertInstructorCourseRelationship(1, 1);
    insertInstructorCourseRelationship(1, 2);
    insertInstructorCourseRelationship(1, 3);
    insertInstructorCourseRelationship(1, 4);
    insertInstructorCourseRelationship(1, 5);
}

bool DatabaseManager::createTATable()
{
    // Create table "TA"
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("CREATE TABLE IF NOT EXISTS ta "
                         "(ta_id INTEGER PRIMARY KEY, "
                         "name TEXT, "
                         "email TEXT, "
                         "GPA real, "
                         "student_number int)");
        if (!ret)
        {
            printLastError("createTATable", query.lastError().databaseText(), query.lastError().driverText());
        }
    }

    return ret;
}

bool DatabaseManager::createInstructorTable()
{
    // Create table "instructor"
    bool ret = false;
    if (db.isOpen())
        {
        QSqlQuery query;
        ret = query.exec("CREATE TABLE IF NOT EXISTS instructor "
                         "(instructor_id INTEGER PRIMARY KEY, "
                         "name TEXT, "
                         "email TEXT, "
                         "department TEXT, "
                         "office_room TEXT)");
        if (!ret)
        {
            printLastError("createInstructorTable", query.lastError().databaseText(), query.lastError().driverText());
        }
    }

    return ret;
}

bool DatabaseManager::createCourseTable()
{
    // Create table "person"
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("CREATE TABLE IF NOT EXISTS course "
                         "(course_id INTEGER PRIMARY KEY, "
                         "course_name TEXT, "
                         "course_code TEXT, "
                         "term TEXT, "
                         "course_description TEXT, "
                         "meeting_time TEXT)");
        if (!ret)
        {
            printLastError("createCourseTable", query.lastError().databaseText(), query.lastError().driverText());
        }
    }

    return ret;
}

bool DatabaseManager::createEvaluationTable()
{
    // Create table "evaluation"
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("CREATE TABLE IF NOT EXISTS evaluation "
                         "(evaluation_id INTEGER PRIMARY KEY, "
                         "rating INTEGER, "
                         "comments TEXT, "
                         "task_id INTEGER, "
                         "FOREIGN KEY(task_id) REFERENCES task(task_id))");
        if (!ret)
        {
            printLastError("createEvaluationTable", query.lastError().databaseText(), query.lastError().driverText());
        }
    }

    return ret;
}

bool DatabaseManager::createTaskTable()
{
    // Create table "task"
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("CREATE TABLE IF NOT EXISTS task "
                         "(task_id INTEGER PRIMARY KEY, "
                         "instructions TEXT, "
                         "type TEXT, "
                         "due_date TEXT, "
                         "progress TEXT, "
                         "course_id INTEGER, "
                         "ta_id INTEGER, "
                         "FOREIGN KEY(course_id) REFERENCES course(course_id), "
                         "FOREIGN KEY(ta_id) REFERENCES ta(ta_id))");

        if (!ret)
        {
            printLastError("createTaskTable", query.lastError().databaseText(), query.lastError().driverText());
        }
    }

    return ret;
}


/****
* Create relationship tables
*****/

bool DatabaseManager::createInstructorCoursesTable()
{
    // Create table "instructorscourse"
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("CREATE TABLE IF NOT EXISTS instructor_courses"
                         "(instructor_id INTEGER references instructor(id), "
                         "course_id INTEGER references course(id), "
                         "PRIMARY KEY (instructor_id, course_id))");
        if (!ret)
        {
            printLastError("createInstructorCoursesTable", query.lastError().databaseText(), query.lastError().driverText());
        }
    }

    return ret;
}

bool DatabaseManager::createCourseTAsTable()
{
    // Create table "courses_tas"
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("CREATE TABLE IF NOT EXISTS course_tas"
                         "(course_id INTEGER references course(id), "
                         "ta_id INTEGER references ta(id), "
                         "PRIMARY KEY (course_id, ta_id))");
        if (!ret)
        {
            printLastError("createCourseTAsTable", query.lastError().databaseText(), query.lastError().driverText());
        }
    }

    return ret;
}

int DatabaseManager::insertInstructor(QString name, QString email,
                              QString department, QString officeRoom)
{
    int newId = -1;
    bool ret = false;

    if (db.isOpen())
    {
         QSqlQuery query;
         ret = query.exec(QString("insert into instructor values(NULL,'%1','%2','%3','%4')")
                         .arg(name).arg(email).arg(department).arg(officeRoom));

        // Get database given autoincrement value
        if (ret)
        {
            newId = query.lastInsertId().toInt();
        }
        else
        {
            printLastError("insertInstructor", query.lastError().databaseText(), query.lastError().driverText());
        }

    }
    return newId;
}




/***
  Entity insert methods
****/
int DatabaseManager::insertTA(QString name, QString email,
                              qreal GPA, qint32 studentNumber)
{
    int newId = -1;
    bool ret = false;

    if (db.isOpen())
    {

        QSqlQuery query;
        ret = query.exec(QString("insert into ta values(NULL,'%1','%2','%3','%4')")
                         .arg(name).arg(email).arg(GPA).arg(studentNumber));

        // Get database given autoincrement value
        if (ret)
        {
            newId = query.lastInsertId().toInt();
        }
        else
        {
            printLastError("insertTA", query.lastError().databaseText(), query.lastError().driverText());
        }
    }
    return newId;
}

int DatabaseManager::insertCourse(QString courseName, QString courseCode, QString term,
                              QString courseDescription, QString meetingTime)
{
    int newId = -1;
    bool ret = false;

    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec(QString("insert into course values(NULL,'%1','%2','%3', '%4','%5')")
                         .arg(courseName).arg(courseCode).arg(term).arg(courseDescription)
                         .arg(meetingTime));

        // Get database given autoincrement value
        if (ret)
        {
            newId = query.lastInsertId().toInt();
        }
        else
        {
            printLastError("insertCourse", query.lastError().databaseText(), query.lastError().driverText());
        }
    }
    return newId;
}

int DatabaseManager::insertTask(QString instructions, QString type, QString dueDate, QString progress,
                                qint32 courseId, qint32 taId)
{
    int newId = -1;
    bool ret = false;

    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec(QString("insert into task values(NULL,'%1','%2','%3', '%4', '%5', '%6')")
                         .arg(instructions).arg(type).arg(dueDate).arg(progress)
                         .arg(courseId).arg(taId));

        // Get database given autoincrement value
        if (ret)
        {
            newId = query.lastInsertId().toInt();
        }
        else
        {
            printLastError("insertTA", query.lastError().databaseText(), query.lastError().driverText());
        }
    }
    return newId;
}

int DatabaseManager::insertEvaluation(qint32 rating, QString comments, qint32 taskId)
{
    int newId = -1;
    bool ret = false;

    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec(QString("insert into evaluation values(NULL,'%1','%2', '%3')")
                         .arg(rating).arg(comments).arg(taskId));

        // Get database given autoincrement value
        if (ret)
        {
            newId = query.lastInsertId().toInt();
        }
        else
        {
            printLastError("insertEval", query.lastError().databaseText(), query.lastError().driverText());
        }
    }
    return newId;
}




/****
  Insert relationship tables
****/
bool DatabaseManager::insertInstructorCourseRelationship(qint32 instructorId, qint32 courseId)
{
    if (db.isOpen())
    {
        QSqlQuery query;
        bool ret = query.exec(QString("insert into instructor_courses values('%1',%2)")
                         .arg(instructorId).arg(courseId));
        if(!ret)
        {
            printLastError("insertInstructorCourseRelationship", query.lastError().databaseText(), query.lastError().driverText());
        }
        return ret;
    }

    return false;
}

bool DatabaseManager::insertCourseTARelationship(qint32 courseId, qint32 taId)
{
    if (db.isOpen())
    {
        QSqlQuery query;
        bool ret = query.exec(QString("insert into course_tas values('%1',%2)")
                         .arg(courseId).arg(taId));
        if(!ret)
        {
            printLastError("insertCourseTARelationship", query.lastError().databaseText(), query.lastError().driverText());
        }
        return ret;
    }

    return false;
}




/***
  Update SQL Methods
***/

bool DatabaseManager::updateTask(qint32 taskId, QString instructions, QString type, QString dueDate, QString progress,
                qint32 courseId, qint32 taId)
{
    if (db.isOpen())
    {
        QSqlQuery query;
        bool ret = query.exec(QString("UPDATE task SET instructions = '%1', type = '%2', due_date = '%3', progress = '%4', course_id = '%5', ta_id = '%6' WHERE task_id = '%7'")
                              .arg(instructions).arg(type).arg(dueDate).arg(progress)
                              .arg(courseId).arg(taId).arg(taskId));
        if(!ret)
        {
            printLastError("updateTask", query.lastError().databaseText(), query.lastError().driverText());
        }
        return ret;
    }

    return false;
}

bool DatabaseManager::updateEvaluation(qint32 evaluationId, qint32 rating, QString comments, qint32 taskId)
{
    if (db.isOpen())
    {
        QSqlQuery query;
        bool ret = query.exec(QString("UPDATE evaluation SET rating = '%1', comments = '%2', task_id = '%3' WHERE evaluation_id = '%4'")
                              .arg(rating).arg(comments).arg(taskId).arg(evaluationId));
        if(!ret)
        {
            printLastError("updateEvaluation", query.lastError().databaseText(), query.lastError().driverText());
        }
        return ret;
    }

    return false;
}


QSqlQuery DatabaseManager::getTaskList(qint32 taId, qint32 courseId)
{

    QSqlQuery query;
    bool ret = query.exec(QString("SELECT task_id, instructions, type, due_date, progress, course_id, ta_id FROM task WHERE course_id = '%1' AND ta_id = '%2'")
                            .arg(taId).arg(courseId));

    if(!ret)
    {
        printLastError("getTaskList", query.lastError().databaseText(), query.lastError().driverText());
    }

    return query;
}

QSqlQuery DatabaseManager::getCourseList(qint32 instructorId)
{
    QSqlQuery query;
    bool ret = query.exec(QString("SELECT course_id, course_name, course_code, term, course_description, meeting_time FROM course NATURAL JOIN instructor_courses WHERE instructor_id = '%1'").arg(instructorId));

    if(!ret)
    {
        printLastError("getCourseList", query.lastError().databaseText(), query.lastError().driverText());
    }
    return query;
}

QSqlQuery DatabaseManager::getTAList(qint32 courseId)
{
    QSqlQuery query;
    bool ret = query.exec(QString("SELECT ta_id, name, email, GPA, student_number, course_id FROM ta NATURAL JOIN course_tas WHERE course_id = '%1'").arg(courseId));

    if(!ret)
    {
        printLastError("getTAList", query.lastError().databaseText(), query.lastError().driverText());
    }

    return query;
}

QSqlQuery DatabaseManager::getEvaluation(qint32 taskId)
{
    QSqlQuery query;
    bool ret = query.exec(QString("SELECT *"
                            "FROM evaluation"
                            "WHERE task_id = '%1'").arg(taskId));

    if(!ret)
    {
        printLastError("getEvaluation", query.lastError().databaseText(), query.lastError().driverText());
    }

    return query;
}


/****
 Delete SQL Methods
****/

bool DatabaseManager::deleteTask(qint32 taskId)
{
    QSqlQuery evalDelQuery, taskDelQuery;

    bool ret;

    // Delete the associated evaluation if it exists
    evalDelQuery.exec(QString("DELETE FROM evaluation WHERE task_id = '%1'").arg(taskId));

    // Delete the task
    ret = taskDelQuery.exec(QString("DELETE FROM task WHERE task_id = '%1'").arg(taskId));


    if(!ret)
    {
        printLastError("deleteTask", taskDelQuery.lastError().databaseText(), taskDelQuery.lastError().driverText());
    }

    return ret;
}

bool DatabaseManager::deleteEvaluation(qint32 evaluationId)
{
    QSqlQuery evalDelQuery;
    // Delete the evaluation

    bool ret = evalDelQuery.exec(QString("DELETE FROM evaluation WHERE task_id = '%1'").arg(evaluationId));

    if(!ret)
    {
        printLastError("deleteEvaluation", evalDelQuery.lastError().databaseText(), evalDelQuery.lastError().driverText());
    }

    return ret;
}
