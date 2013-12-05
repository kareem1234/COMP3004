#include "dbcourse.h"

#include <QSqlQuery>
#include <QVariant>
#include "databasemanager.h"

#include "course.h"
#include "instructor.h"
#include "ta.h"

DBCourse::DBCourse(DatabaseManager& dbMan) :
    db(dbMan)
{
}


vector<Course> DBCourse::getCourseList(Instructor instructor)
{
    QSqlQuery query = getCourseList(instructor.getId());

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


QSqlQuery DBCourse::getCourseList(int instructorId)
{
    QSqlQuery query;
    bool ret = query.exec(QString("SELECT course_id, course_name, course_code, term, course_description, meeting_time FROM course NATURAL JOIN instructor_courses WHERE instructor_id = '%1'").arg(instructorId));

    if(!ret)
    {
        db.printLastError("getCourseList", query.lastError().databaseText(), query.lastError().driverText());
    }
    return query;
}



Course DBCourse::getCurrentCourse(TA ta)
{
    QSqlQuery query = getCurrentCourse(ta.getId());

    bool ret = false;
    Course course;

    if (query.next())
    {
        course.setId(query.value(0).toInt());
        course.setCourseName(query.value(1).toString().toUtf8().constData());
        course.setCourseCode(query.value(2).toString().toUtf8().constData());
        course.setTerm(query.value(3).toString().toUtf8().constData());
        course.setCourseDescription(query.value(4).toString().toUtf8().constData());
        course.setMeetingTime(query.value(5).toString().toUtf8().constData());

        ret = true;
    }

    return course;
}


QSqlQuery DBCourse::getCurrentCourse(int taId)
{
    QSqlQuery query;
    bool ret = query.exec(QString("SELECT course_id, course_name, course_code, term, course_description, meeting_time FROM course NATURAL JOIN course_tas WHERE ta_id = '%1' AND current = 1").arg(taId));

    if(!ret)
    {
        db.printLastError("getCurrentCourse", query.lastError().databaseText(), query.lastError().driverText());
    }
    return query;
}
