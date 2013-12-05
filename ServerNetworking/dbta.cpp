#include "dbta.h"

#include <QSqlQuery>
#include <QVariant>
#include "databasemanager.h"
#include "ta.h"
#include "course.h"

DBTa::DBTa(DatabaseManager& dbMan) :
    db(dbMan)
{
}



// Get TA from email
TA DBTa::getTA(string email)
{
    QSqlQuery query = getTAQuery(email);

    bool ret = false;

    TA ta;

    if (query.next())
    {
        ta.setId(query.value(0).toInt());
        ta.setName(query.value(1).toString().toUtf8().constData());
        ta.setEmail(query.value(2).toString().toUtf8().constData());
        ta.setGPA(query.value(3).toInt());
        ta.setStudentNumber(query.value(4).toInt());
        ta.setCourseId(query.value(5).toInt());
        ret = true;
    }

    return ta;
}


QSqlQuery DBTa::getTAQuery(string email)
{
    QSqlQuery query;
    bool ret = query.exec(QString("SELECT * FROM ta WHERE email = '%1'").arg(QString::fromStdString(email)));

    if(!ret)
    {
        db.printLastError("getTA", query.lastError().databaseText(), query.lastError().driverText());
    }

    return query;
}





// Get TA List
vector<TA> DBTa::getTAList(Course course)
{
    QSqlQuery query = getTAList(course.getId());

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


QSqlQuery DBTa::getTAList(qint32 courseId)
{
    QSqlQuery query;
    bool ret = query.exec(QString("SELECT ta_id, name, email, GPA, student_number, course_id FROM ta NATURAL JOIN course_tas WHERE course_id = '%1'").arg(courseId));

    if(!ret)
    {
        db.printLastError("getTAList", query.lastError().databaseText(), query.lastError().driverText());
    }

    return query;
}
