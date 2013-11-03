#ifndef TA_H
#define TA_H
 #include <QString>
#include "user.h"


class TA : public User
{
public:
    TA();
    TA(int , int , std::string ,int ,std::string, int, std::string,int , std::string);
    TA(std::string);

    //set methods
    void   setGPA(int);
    void   setCourseId(int);
    void   setYearStanding(int);
    void   setStudentNumber(int);
    void   setFieldOfStudy(std::string);
    void   setOfficeRoom(std::string);

    //get methods
    int         getCourseId();
    int         getGPA();
    int         getYearStanding();
    int         getStudentNumber();
    std::string getOfficeRoom();
    std::string getFieldOfStudy();

    //toString method
    std::string toString();

private:
    int         courseID;
    int         gpa;
    int         yearStanding;
    int         studentNumber;
    std::string fieldOfStudy;
    std::string officeRoom;

};

#endif // TA_H
