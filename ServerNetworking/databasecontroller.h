#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H

#include <QObject>
#include "databasemanager.h"
#include <vector>

#include "dbinstructor.h"
#include "dbta.h"
#include "dbcourse.h"
#include "dbtask.h"
#include "dbevaluation.h"

class Instructor;
class TA;
class Course;
class Task;
class Evaluation;
class DatabaseManager;

using namespace std;

class DatabaseController : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseController(QObject *parent = 0);

    bool initDatabase();




    // Database get methods
    vector<Task> getTaskListForTACourse(TA, Course);
    vector<TA> getTAList(Course);
    vector<Course> getCourseList(Instructor);
    Evaluation getEvaluation(Task);
    Course getCurrentCourse(TA);

    // Login Methods
    TA loginTA(string email);
    Instructor loginInstructor(string email);

    // Database save methods
    bool saveTask(TA ta, Task);
    bool saveEvaluation(Evaluation);

    // Database delete methods
    bool deleteTask(Task);
    bool deleteEvaluation(Evaluation);



private:
    DatabaseManager dbManager;

    DBTa dbTa;
    DBInstructor dbInstructor;
    DBCourse dbCourse;
    DBTask dbTask;
    DBEvaluation dbEvaluation;

signals:
    
public slots:
    
};

#endif // DATABASECONTROLLER_H
