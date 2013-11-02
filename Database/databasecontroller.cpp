#include "databasecontroller.h"

#include <QSqlQuery>
#include <vector>

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
    success = dbManager.buildDB();
   // success = dbManager.populateDB();

    dbManager.deleteDB();

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
        ret = dbManager.insertTask(task.getInstructions(), task.getType(), task.getDueDate(), task.getProgress(),
                                   ta.getCourseId(), ta.getId());
    }
    // Otherwise update the record
    else
    {
        ret = dbManager.updateTask(task.getId(), task.getInstructions(), task.getType(), task.getDueDate(), task.getProgress(),
                                   ta.courseId(), ta.getId());
    }

    return ret;
}

bool DatabaseController::saveEvaluation(Evaluation eval)
{
    bool ret = false;

    // If it's a new evaluation it won't yet have an id, so insert it
    if (task.getId() == 0)
    {
        ret = dbManager.insertEvaluation(eval.getRating(), eval.getComments(), eval.getTaskId());
    }
    // Otherwise update the record
    else
    {
        ret = dbManager.updateEvaluation(eval.getId(), eval.getRating(), eval.getComments(), eval.getTaskId());
    }


    return ret;
}




/***
  Delete Entities
***/

bool DatabaseController::deleteTask(Task task)
{
    return dbManager.deleteTask(task.getId);
}

bool DatabaseController::deleteEvaluation(Evaluation eval)
{
    return dbManager.deleteEvaluation(eval.getId);
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
        task.setInstructions(query.value(1).toString());
        task.setType(query.value(2).toString());
        task.setDueDate(query.value(3).toString());
        task.setProgress(query.value(4).toString());
        task.setCourseId(query.value(5).toString());
        task.setTaId(query.value(6).toString());

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
        ta.setName(query.value(1).toString());
        ta.setEmail(query.value(2).toString());
        ta.setGPA(query.value(3).toString());
        ta.setStudentNumber(query.value(4).toString());
        ta.setCourseId(query.value(5).toString());

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
        eval.setComments(query.value(2).toString());
        eval.setTaskId(query.value(3).toInt());
        ret = true;
    }

    return eval;
}





