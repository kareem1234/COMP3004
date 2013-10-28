#ifndef TA_H
#define TA_H
 #include <QString>
#include "user.h"
#include "course.h"
#include "task.h"

class TA : public User
{
public:
    TA();
    //TA(const TA&);
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

    std::string tostring();

private:
    int         GPA;
    bool        newTask;
    std::string fieldOfStudy;
    int         yearStanding;
    int         studentNumber;
    std::string officeRoom;
    Task        aTask;
    Course      aCourse;
};

#endif // TA_H
