#ifndef DBTASK_H
#define DBTASK_H

#include <QObject>
#include <vector>

class QSqlQuery;
class DatabaseManager;
class TA;
class Task;
class Course;

using namespace std;

class DBTask : public QObject
{
    Q_OBJECT
public:
    DBTask(DatabaseManager& dbMan);

    vector<Task> getTaskListForTACourse(TA, Course);
    bool saveTask(TA, Task);
    bool deleteTask(Task);

private:
    bool insertTask(QString instructions, QString type, QString dueDate, QString progress,
                    qint32 courseId, qint32 taId);
    bool updateTask(qint32 taskId, QString instructions, QString type, QString dueDate, QString progress,
                    qint32 courseId, qint32 taId);
    QSqlQuery getTaskList(qint32 taId, qint32 courseId);
    bool deleteTask(qint32);

    DatabaseManager& db;

    
signals:
    
public slots:
    
};

#endif // DBTASK_H
