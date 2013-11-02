#ifndef TA_H
#define TA_H
 #include <QString>
#include "user.h"


class TA : public User
{
public:
    TA();
    TA(std::string);

    //set methods
    void   setGPA(int);
    void   setYearStanding(int);
    void   setStudentNumber(int);
    void   setFieldOfStudy(std::string);
    void   setOfficeRoom(std::string);

    //get methods
    int         getGPA();
    int         getYearStanding();
    int         getStudentNumber();
    std::string getOfficeRoom();
    std::string getFieldOfStudy();

    //toString method
    std::string toString();

private:
    int         gpa;
    int         yearStanding;
    int         studentNumber;
    std::string fieldOfStudy;
    std::string officeRoom;

};

#endif // TA_H
