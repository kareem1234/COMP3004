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

    //set methods
    void setDepartment(std::string);
    void setOfficeRoom(std::string);

    //get methods
    std::string getDepartment();
    std::string getOfficeRoom();

    //toString methods
    std::string toString();

private:
    std::string officeRoom;
    std::string department;

};

#endif // INSTRUCTOR_H
