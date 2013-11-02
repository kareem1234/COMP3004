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
    int insertInstructor(QString firstName, QString lastName, QString email,
                         QString department, QString office_room);
    int insertTA(QString firstName, QString lastName, QString email,
                 qreal GPA, qint32 studentNumber);
    int insertCourse(QString courseName, QString courseCode, QString term,
                     QString courseDescription, QString meetingTime);
    int insertTask(QString instructions, QString type, QString dueDate, QString progress,
                   qint32 courseId, qint32 taId);
    int insertEvaluation(qint32 rating, QString comments, qint32 taskId);
    bool insertInstructorCourseRelationship(qint32 instructorId, qint32 courseId);
    bool insertCourseTARelationship(qint32 courseId, qint32 taId);


    // Select SQL Methods
    QSqlQuery getTaskList(qint32 taId, qint32 courseId);
    QSqlQuery getCourseList(qint32 instructorId);
    QSqlQuery getTAList(qint32 courseId);
    QSqlQuery getEvaluation(qint32 taskId);

    // Delete SQL Methods
    bool deleteTask(qint32 taskId);
    bool deleteEvaluation(qint32 evaluationId);

    // Update SQL Methods
    bool updateTask(qint32 taskId, QString instructions, QString type, QString dueDate, QString progress,
                    qint32 courseId, qint32 taId);
    bool updateEvaluation(qint32 evaluationId, qint32 rating, QString comments, qint32 taskId);



    void printLastError(QString errName, QString databaseText, QString driverText);
    QSqlError lastError();

private:
    QSqlDatabase db;
signals:

public slots:

};

#endif // DATABASEMANAGER_H
