#include "dbtask.h"

#include <QSqlQuery>
#include <QVariant>

#include "ta.h"
#include "course.h"
#include "task.h"

#include "databasemanager.h"


DBTask::DBTask(DatabaseManager& dbMan) :
    db(dbMan)
{
}


// Get Task
vector<Task> DBTask::getTaskListForTACourse(TA ta, Course course)
{
    QSqlQuery query = getTaskList(ta.getId(), course.getId());

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


QSqlQuery DBTask::getTaskList(qint32 taId, qint32 courseId)
{

    QSqlQuery query;
    bool ret = query.exec(QString("SELECT task_id, instructions, type, due_date, progress, course_id, ta_id FROM task WHERE course_id = '%1' AND ta_id = '%2'")
                            .arg(courseId).arg(taId));

    if(!ret)
    {
        db.printLastError("getTaskList", query.lastError().databaseText(), query.lastError().driverText());
    }

    return query;
}






// Save Task
bool DBTask::saveTask(TA ta, Task task)
{
    bool ret = false;

    // If it's a new task it won't yet have an id, so insert it
    if (task.getId() == 0)
    {
        ret = insertTask(QString::fromStdString(task.getInstructions()), QString::fromStdString(task.getType()),
                                   QString::fromStdString(task.getDueDate()), QString::fromStdString(task.getProgress()),
                                   ta.getCourseId(), ta.getId());
    }
    // Otherwise update the record
    else
    {
        ret = updateTask(task.getId(), QString::fromStdString(task.getInstructions()), QString::fromStdString(task.getType()),
                                  QString::fromStdString(task.getDueDate()), QString::fromStdString(task.getProgress()),
                                   ta.getCourseId(), ta.getId());
    }

    return ret;
}


bool DBTask::insertTask(QString instructions, QString type, QString dueDate, QString progress,
                                qint32 courseId, qint32 taId)
{
    bool ret = false;

    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec(QString("insert into task values(NULL,'%1','%2','%3', '%4', '%5', '%6')")
                         .arg(instructions).arg(type).arg(dueDate).arg(progress)
                         .arg(courseId).arg(taId));

        if (!ret)
        {
           db.printLastError("insertTA", query.lastError().databaseText(), query.lastError().driverText());
        }
    }
    return ret;
}


bool DBTask::updateTask(qint32 taskId, QString instructions, QString type, QString dueDate, QString progress,
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
            db.printLastError("updateTask", query.lastError().databaseText(), query.lastError().driverText());
        }
        return ret;
    }

    return false;
}





// Delete Task
bool DBTask::deleteTask(Task task)
{
    return deleteTask(qint32(task.getId()));
}


bool DBTask::deleteTask(qint32 taskId)
{
    QSqlQuery evalDelQuery, taskDelQuery;

    bool ret;

    // Delete the associated evaluation if it exists
    evalDelQuery.exec(QString("DELETE FROM evaluation WHERE task_id = '%1'").arg(taskId));

    // Delete the task
    ret = taskDelQuery.exec(QString("DELETE FROM task WHERE task_id = '%1'").arg(taskId));


    if(!ret)
    {
        db.printLastError("deleteTask", taskDelQuery.lastError().databaseText(), taskDelQuery.lastError().driverText());
    }

    return ret;
}


