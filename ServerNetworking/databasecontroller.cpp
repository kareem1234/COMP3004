#include "databasecontroller.h"

#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

#include "instructor.h"
#include "ta.h"
#include "course.h"
#include "task.h"
#include "evaluation.h"



DatabaseController::DatabaseController(QObject *parent) :
    QObject(parent), dbTa(dbManager), dbInstructor(dbManager),
    dbTask(dbManager), dbEvaluation(dbManager),
    dbCourse(dbManager)
{

    initDatabase();


}


bool DatabaseController::initDatabase()
{
    bool success = false;

    success = dbManager.openDB();


    return success;
}



/***
  Save Entity Objects
***/

bool DatabaseController::saveTask(TA ta, Task task)
{
    return dbTask.saveTask(ta, task);
}

bool DatabaseController::saveEvaluation(Evaluation eval)
{
   return dbEvaluation.saveEvaluation(eval);
}




/***
  Delete Entities
***/

bool DatabaseController::deleteTask(Task task)
{
    return dbTask.deleteTask(task);
}

bool DatabaseController::deleteEvaluation(Evaluation eval)
{
    return dbEvaluation.deleteEvaluation(eval);
}




/***
  Get Entity Objects
***/

TA DatabaseController::loginTA(string email)
{
    return dbTa.getTA(email);
}

Instructor DatabaseController::loginInstructor(string email)
{
    return dbInstructor.getInstructor(email);
}

Course DatabaseController::getCurrentCourse(TA ta)
{
    return dbCourse.getCurrentCourse(ta);
}

vector<Task> DatabaseController::getTaskListForTACourse(TA ta, Course course)
{
    return dbTask.getTaskListForTACourse(ta, course);
}

vector<TA> DatabaseController::getTAList(Course course)
{
    return dbTa.getTAList(course);
}

Evaluation DatabaseController::getEvaluation(Task task)
{
    return dbEvaluation.getEvaluation(task);
}


vector<Course> DatabaseController::getCourseList(Instructor instructor)
{
    return dbCourse.getCourseList(instructor);
}





