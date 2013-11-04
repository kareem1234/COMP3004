#ifndef TA_H
#define TA_H
 #include <QString>
#include "user.h"


class TA : public User
{
public:
    TA();
    TA(int tempID, int tempCourseID, std::string tempName,int tempGPA,
           std::string tempEmail, int tempStudentNumber);
    TA(std::string);

    //set methods
    void   setGPA(int);
    void   setCourseId(int);
    void   setStudentNumber(int);
    //void   setYearStanding(int);
    //void   setFieldOfStudy(std::string);
    //void   setOfficeRoom(std::string);

    //get methods
    int         getCourseId();
    int         getGPA();
    int         getStudentNumber();
    //int         getYearStanding();
    //std::string getOfficeRoom();
    //std::string getFieldOfStudy();

    //toString method
    std::string toString();

private:
    int         courseID;
    int         gpa;
    int         studentNumber;
    //int         yearStanding;
    //std::string fieldOfStudy;
    //std::string officeRoom;

};

#endif // TA_H
