#ifndef TA_H
#define TA_H
 #include <QString>
#include "user.h"


class TA : public User
{
public:
    TA();
    TA(std::string);
    void   setGPA(int);
    void   setNewTaskBoolean(bool);
    void   setFieldOfStudy(std::string);
    void   setYearStanding(int);
    void   setStudentNumber(int);
    void   setOfficeRoom(std::string);


    bool        getNewTaskBoolean();
    int         getGPA();
    int         getYearStanding();
    int         getStudentNumber();
    std::string getFieldOfStudy();
    std::string getOfficeRoom();

    std::string toString();

private:
    int         gpa;
    int         yearStanding;
    int         studentNumber;
    //bool        newTask;
    std::string fieldOfStudy;
    std::string officeRoom;

};

#endif // TA_H
