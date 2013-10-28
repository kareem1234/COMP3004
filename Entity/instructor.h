#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "user.h";
class Instructor : public User
{
public:
    Instructor();
    void setDepartment(String);
    void setOfficeRoom(String);
    String getDepartment();
    String getOfficeRoom();
    String toString();
private:
    String officeRoom;
    String department;
};

#endif // INSTRUCTOR_H
