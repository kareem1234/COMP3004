#ifndef DBEVALUATION_H
#define DBEVALUATION_H

#include <QObject>

class QSqlQuery;
class DatabaseManager;
class Evaluation;
class Task;

class DBEvaluation : public QObject
{
    Q_OBJECT
public:
    DBEvaluation(DatabaseManager& dbMan);


    Evaluation getEvaluation(Task);
    bool saveEvaluation(Evaluation);
    bool deleteEvaluation(Evaluation);

private:


    bool insertEvaluation(qint32 rating, QString comments, qint32 taskId);
    QSqlQuery getEvaluation(qint32 taskId);
    bool deleteEvaluation(qint32 id);
    bool updateEvaluation(qint32 id, int rating, QString comments, int taskId);

    DatabaseManager& db;
    
signals:
    
public slots:
    
};

#endif // DBEVALUATION_H
