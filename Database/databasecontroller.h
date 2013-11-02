#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H

#include <QObject>
#include "databasemanager.h"

class Instructor;
class TA;
class Course;
class Task;
class Evaluation;
class DatabaseManager;

class DatabaseController : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseController(QObject *parent = 0);

    bool initDatabase();

    // Database get methods
    QVector<Task> getTaskListForTACourse(TA, Course);
    QVector<TA> getTAList(Instructor, Course);
    QVector<Course> getCourseList(Instructor);
    Evaluation getEvaluation(Task);

    // Database save methods
    bool saveTask(TA ta, Task);
    bool saveEvaluation(Evaluation);

    // Database delete methods
    bool deleteTask(Task);
    bool deleteEvaluation(Evaluation);



private:
    DatabaseManager dbManager;
signals:
    
public slots:
    
};

#endif // DATABASECONTROLLER_H
