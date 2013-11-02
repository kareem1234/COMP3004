#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "user.h"
#include "course.h"

class Instructor : public User
{
public:
    Instructor();
    Instructor(std::string);
    Instructor(std::string, std::string);
    void setDepartment(std::string);
    void setOfficeRoom(std::string);
    std::string getDepartment();
    std::string getOfficeRoom();
    std::string toString();
private:
    std::string officeRoom;
    std::string department;

};

#endif // INSTRUCTOR_H
