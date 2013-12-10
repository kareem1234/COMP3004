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
    bool isDbOpened =  db.open();

    if(!dbExists)
    {
        buildDB();
        populateDB();
    }

    // Open database
    return isDbOpened;
}

bool DatabaseManager::isOpen()
{
    return db.isOpen();
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
    db.exec(QString("INSERT INTO course VALUES(NULL, 'Software Engineering', 'COMP3004', 'F2013', 'Design some sofware.', 'Tuesday')"));
    db.exec(QString("INSERT INTO course VALUES(NULL, 'Programming Paradigms', 'COMP3007', 'F2013', 'Learn about programming languages.', 'Wednesday')"));
    db.exec(QString("INSERT INTO course VALUES(NULL, 'Intro to Computer Science', 'COMP1405', 'F2013', 'Learn some basic computery things.', 'Friday')"));
    db.exec(QString("INSERT INTO course VALUES(NULL, 'Systems Programming', 'COMP2401', 'F2013', 'Do some low level things.', 'Monday')"));
    db.exec(QString("INSERT INTO course VALUES(NULL, 'Discrete Mathematics', 'COMP1805', 'F2013', 'Logic and proofs.', 'Thursday')"));

    db.exec(QString("INSERT INTO ta VALUES(NULL, 'Mary Sue', 'mary@carleton.ca', 4.0, 100869040)"));
    db.exec(QString("INSERT INTO ta VALUES(NULL, 'Billy Bob', 'billy@carleton.ca', 4.0, 100869039)"));
    db.exec(QString("INSERT INTO ta VALUES(NULL, 'Sally Jane', 'sally@carleton.ca', 4.0, 100869037)"));

    db.exec(QString("INSERT INTO course_tas VALUES(1, 1, 1)"));
    db.exec(QString("INSERT INTO course_tas VALUES(1, 2, 1)"));
    db.exec(QString("INSERT INTO course_tas VALUES(2, 3, 1)"));

    db.exec(QString("INSERT INTO instructor VALUES(NULL, 'Edna Krabappel', 'edna@carleton.ca', 'CS', 'HP5120')"));
    db.exec(QString("INSERT INTO instructor VALUES(NULL, 'Elizabeth Hoover', 'elizabeth@carleton.ca', 'CS', 'HP5121')"));

    db.exec(QString("INSERT INTO instructor_courses VALUES(1, 1)"));
    db.exec(QString("INSERT INTO instructor_courses VALUES(1, 2)"));
    db.exec(QString("INSERT INTO instructor_courses VALUES(2, 3)"));
    db.exec(QString("INSERT INTO instructor_courses VALUES(2, 4)"));
}

/*
QSqlQuery DatabaseManager::exec(const QString & query = QString() ) const
{
  return db.exec(query);
}
*/


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
                         "current INTEGER, "
                         "PRIMARY KEY (course_id, ta_id))");
        if (!ret)
        {
            printLastError("createCourseTAsTable", query.lastError().databaseText(), query.lastError().driverText());
        }
    }

    return ret;
}
