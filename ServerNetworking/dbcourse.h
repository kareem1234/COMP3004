#ifndef DBCOURSE_H
#define DBCOURSE_H

#include <QObject>
#include <vector>

class Course;
class Instructor;
class TA;
class DatabaseManager;
class QSqlQuery;

using namespace std;

class DBCourse : public QObject
{
    Q_OBJECT
public:
    DBCourse(DatabaseManager& dbMan);

    vector<Course> getCourseList(Instructor);
    Course getCurrentCourse(TA);

private:
    int insertCourse(QString courseName, QString courseCode, QString term, QString courseDescription, QString meetingTime);
    QSqlQuery getCourseList(int);
    QSqlQuery getCurrentCourse(int taId);

    DatabaseManager& db;

signals:
    
public slots:
    
};

#endif // DBCOURSE_H
