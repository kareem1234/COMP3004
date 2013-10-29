#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "user.h"
#include "course.h"

class Instructor : public User
{
public:
    Instructor();
    Instructor(std::string);
    void setDepartment(std::string);
    void setOfficeRoom(std::string);
    std::string getDepartment();
    std::string getOfficeRoom();
    std::string tostring();
private:
    std::string officeRoom;
    std::string department;
    Course aCourse;

};

#endif // INSTRUCTOR_H
