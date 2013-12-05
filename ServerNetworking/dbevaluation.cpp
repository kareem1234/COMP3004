#include "dbevaluation.h"

#include "databasemanager.h"
#include "evaluation.h"
#include "task.h"

#include <QSqlQuery>
#include <QVariant>

DBEvaluation::DBEvaluation(DatabaseManager& dbMan) :
    db(dbMan)
{
}


// Get Evaluation

Evaluation DBEvaluation::getEvaluation(Task task)
{
    QSqlQuery query = getEvaluation(task.getId());

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


QSqlQuery DBEvaluation::getEvaluation(qint32 taskId)
{
    QSqlQuery query;
    bool ret = query.exec(QString("SELECT * FROM evaluation WHERE task_id = '%1'").arg(taskId));

    if(!ret)
    {
        db.printLastError("getEvaluation", query.lastError().databaseText(), query.lastError().driverText());
    }

    return query;
}





// Save Evaluation
bool DBEvaluation::saveEvaluation(Evaluation eval)
{
    bool ret = false;

    // If it's a new evaluation it won't yet have an id, so insert it
    if (eval.getId() == 0)
    {
        ret = insertEvaluation(eval.getRating(), QString::fromStdString(eval.getComment()), eval.getTaskId());
    }
    // Otherwise update the record
    else
    {
        ret = updateEvaluation(eval.getId(), eval.getRating(), QString::fromStdString(eval.getComment()), eval.getTaskId());
    }

    return ret;
}


bool DBEvaluation::insertEvaluation(qint32 rating, QString comments, qint32 taskId)
{
    bool ret = false;

    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec(QString("insert into evaluation values(NULL,'%1','%2', '%3')")
                         .arg(rating).arg(comments).arg(taskId));

        if (!ret)
        {
            db.printLastError("insertEval", query.lastError().databaseText(), query.lastError().driverText());
        }
    }
    return ret;
}


bool DBEvaluation::updateEvaluation(qint32 evaluationId, qint32 rating, QString comments, qint32 taskId)
{
    bool ret = false;

    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec(QString("UPDATE evaluation SET rating = '%1', comments = '%2', task_id = '%3' WHERE evaluation_id = '%4'")
                              .arg(rating).arg(comments).arg(taskId).arg(evaluationId));
        if(!ret)
        {
            db.printLastError("updateEvaluation", query.lastError().databaseText(), query.lastError().driverText());
        }
        return ret;
    }

    return ret;
}





// Delete Evaluation
bool DBEvaluation::deleteEvaluation(Evaluation eval)
{
    return deleteEvaluation(qint32(eval.getId()));
}


bool DBEvaluation::deleteEvaluation(qint32 evaluationId)
{
    QSqlQuery evalDelQuery;
    // Delete the evaluation

    bool ret = evalDelQuery.exec(QString("DELETE FROM evaluation WHERE evaluation_id = '%1'").arg(evaluationId));

    if(!ret)
    {
        db.printLastError("deleteEvaluation", evalDelQuery.lastError().databaseText(), evalDelQuery.lastError().driverText());
    }

    return ret;
}
