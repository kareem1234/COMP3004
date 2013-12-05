#include "dbinstructor.h"

#include <QSqlQuery>
#include <QVariant>

#include "instructor.h"
#include "databasemanager.h"

DBInstructor::DBInstructor(DatabaseManager& dbMan) :
    db(dbMan)
{
}



// Get TA from email
Instructor DBInstructor::getInstructor(string email)
{
    QSqlQuery query = getInstructorQuery(email);

    bool ret = false;

    Instructor instructor;

    if (query.next())
    {
        instructor.setId(query.value(0).toInt());
        instructor.setName(query.value(1).toString().toUtf8().constData());
        instructor.setEmail(query.value(2).toString().toUtf8().constData());
        instructor.setDepartment(query.value(3).toString().toUtf8().constData());
        instructor.setOfficeRoom(query.value(4).toString().toUtf8().constData());

        ret = true;
    }

    return instructor;
}


QSqlQuery DBInstructor::getInstructorQuery(string email)
{
    QSqlQuery query;
    bool ret = query.exec(QString("SELECT * FROM instructor WHERE email = '%1'").arg(QString::fromStdString(email)));

    if(!ret)
    {
        db.printLastError("getInstructor", query.lastError().databaseText(), query.lastError().driverText());
    }

    return query;
}
