#ifndef DBTA_H
#define DBTA_H

#include <vector>
#include <QObject>

using namespace std;

class DatabaseManager;
class Course;
class TA;
class QSqlQuery;

class DBTa : public QObject
{
    Q_OBJECT
public:
    DBTa(DatabaseManager& dbMan);
    
    vector<TA> getTAList(Course);
    TA getTA(string email);

private:
    QSqlQuery getTAList(qint32 courseId);
    QSqlQuery getTAQuery(string email);

    DatabaseManager& db;
};

#endif // DBTA_H
