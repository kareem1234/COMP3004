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
    QObject(parent)
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
    bool ret = false;

    // If it's a new task it won't yet have an id, so insert it
    if (task.getId() == 0)
    {
        ret = dbManager.insertTask(QString::fromStdString(task.getInstructions()), QString::fromStdString(task.getType()),
                                   QString::fromStdString(task.getDueDate()), QString::fromStdString(task.getProgress()),
                                   ta.getCourseId(), ta.getId());
    }
    // Otherwise update the record
    else
    {
        ret = dbManager.updateTask(task.getId(), QString::fromStdString(task.getInstructions()), QString::fromStdString(task.getType()),
                                  QString::fromStdString(task.getDueDate()), QString::fromStdString(task.getProgress()),
                                   ta.getCourseId(), ta.getId());
    }

    return ret;
}

bool DatabaseController::saveEvaluation(Evaluation eval)
{
    bool ret = false;

    // If it's a new evaluation it won't yet have an id, so insert it
    if (eval.getId() == 0)
    {
        ret = dbManager.insertEvaluation(eval.getRating(), QString::fromStdString(eval.getComment()), eval.getTaskId());
    }
    // Otherwise update the record
    else
    {
        ret = dbManager.updateEvaluation(eval.getId(), eval.getRating(), QString::fromStdString(eval.getComment()), eval.getTaskId());
    }


    return ret;
}




/***
  Delete Entities
***/

bool DatabaseController::deleteTask(Task task)
{
    return dbManager.deleteTask(qint32(task.getId()));
}

bool DatabaseController::deleteEvaluation(Evaluation eval)
{
    return dbManager.deleteEvaluation(qint32(eval.getId()));
}




/***
  Get Entity Objects
***/

vector<Task> DatabaseController::getTaskListForTACourse(TA ta, Course course)
{
    QSqlQuery query = dbManager.getTaskList(ta.getId(), course.getId());

    bool ret = false;

    vector<Task> taskList;

    while (query.next())
    {
        Task task;

        task.setId(query.value(0).toInt());
        task.setInstructions(query.value(1).toString().toUtf8().constData());
        task.setType(query.value(2).toString().toUtf8().constData());
        task.setDueDate(query.value(3).toString().toUtf8().constData());
        task.setProgress(query.value(4).toString().toUtf8().constData());
        task.setCourseId(query.value(5).toInt());
        task.setTaId(query.value(6).toInt());

        taskList.push_back(task);
        ret = true;
    }

    return taskList;
}

vector<TA> DatabaseController::getTAList(Course course)
{
    QSqlQuery query = dbManager.getTAList(course.getId());

    bool ret = false;

    vector<TA> taList;

    while (query.next())
    {
        TA ta;

        ta.setId(query.value(0).toInt());
        ta.setName(query.value(1).toString().toUtf8().constData());
        ta.setEmail(query.value(2).toString().toUtf8().constData());
        ta.setGPA(query.value(3).toInt());
        ta.setStudentNumber(query.value(4).toInt());
        ta.setCourseId(query.value(5).toInt());

        taList.push_back(ta);
        ret = true;
    }

    return taList;
}

Evaluation DatabaseController::getEvaluation(Task task)
{
    QSqlQuery query = dbManager.getEvaluation(task.getId());

    bool ret = false;

    Evaluation eval;

    if (query.next())
    {
        eval.setId(query.value(0).toInt());
        eval.setRating(query.value(1).toInt());
        eval.setComment(query.value(2).toString().toUtf8().constData());
        eval.setTaskId(query.value(3).toInt());
        ret = true;
    }

    return eval;
}

vector<Course> DatabaseController::getCourseList(Instructor instructor)
{
    QSqlQuery query = dbManager.getCourseList(instructor.getId());

    bool ret = false;

    vector<Course> courseList;

    while (query.next())
    {
        Course course;

        course.setId(query.value(0).toInt());
        course.setCourseName(query.value(1).toString().toUtf8().constData());
        course.setCourseCode(query.value(2).toString().toUtf8().constData());
        course.setTerm(query.value(3).toString().toUtf8().constData());
        course.setCourseDescription(query.value(4).toString().toUtf8().constData());
        course.setMeetingTime(query.value(5).toString().toUtf8().constData());

        courseList.push_back(course);
        ret = true;
    }

    return courseList;


}





