#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <sstream>
#include <stdlib.h>
class Course
{
public:
    Course();
    Course(std::string);
    std::string toString();
private:
    std::string courseName;
    std::string courseCode;
    std::string courseDescription;
    std::string term;
    int id;
    //This isnt the right synta
    //Date meetingTime
};

#endif // COURSE_H
