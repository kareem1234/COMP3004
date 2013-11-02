#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>


class DatabaseManager : public QObject
{
    Q_OBJECT

public:
    explicit DatabaseManager(QObject *parent = 0);
    bool openDB();
    bool buildDB();
    void populateDB();
    bool deleteDB();



    // Create SQL Table Methods
    bool createTATable();
    bool createInstructorTable();
    bool createCourseTable();
    bool createTaskTable();
    bool createEvaluationTable();
    bool createInstructorCoursesTable();
    bool createCourseTAsTable();
    bool createTATasksTable();
    bool createTaskEvaluationsTable();
    bool createCourseTATasksTable();


    // Insert SQL Record Methods
    int insertInstructor(QString name, QString email,
                         QString department, QString office_room);
    int insertTA(QString name, QString email,
                 qreal GPA, qint32 studentNumber);
    int insertCourse(QString courseName, QString courseCode, QString term,
                     QString courseDescription, QString meetingTime);
    int insertTask(QString instructions, QString type, QString dueDate, QString progress,
                   qint32 courseId, qint32 taId);
    int insertEvaluation(qint32 rating, QString comments, qint32 taskId);
    bool insertInstructorCourseRelationship(qint32 instructorId, qint32 courseId);
    bool insertCourseTARelationship(qint32 courseId, qint32 taId);


    // Select SQL Methods
    QSqlQuery getTaskList(qint32, qint32);
    QSqlQuery getCourseList(qint32);
    QSqlQuery getTAList(qint32);
    QSqlQuery getEvaluation(qint32);

    // Delete SQL Methods
    bool deleteTask(qint32);
    bool deleteEvaluation(qint32);

    // Update SQL Methods
    bool updateTask(qint32, QString, QString, QString, QString,
                    qint32, qint32);
    bool updateEvaluation(qint32, qint32, QString, qint32);



    void printLastError(QString errName, QString databaseText, QString driverText);
    QSqlError lastError();

private:
    QSqlDatabase db;
signals:

public slots:

};

#endif // DATABASEMANAGER_H
