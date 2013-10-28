#ifndef TA_H
#define TA_H

#include "user.h";

class TA : public User
{
public:
    TA();
    void   setGPA(String);
    void   setNewTaskBoolean();
    void   setFieldOfStudy();
    void   setYearStanding();
    void   setStudentNumber();
    void   setOfficeRoom(String);

    int    getGPA(String);
    bool   getNewTaskBoolean();
    String getFieldOfStudy();
    int    getYearStanding();
    int    getStudentNumber();
    void   getOfficeRoom(String);

    String toString();

private:
    int GPA;
    boolean newTask;
    String fieldOfStudy;
    int yearStanding;
    int studentNumber;
    String officeRoom;
};

#endif // TA_H
