#ifndef COURSE_H
#define COURSE_H

#include<iostream>
using namespace std;

class Course{
public:
    Course();
    string toString();
private:
    string courseName;
    string courseCode;
    string courseDescription;
    string term;
    //This isnt the right synta
    //Date meetingTime
};

#endif // COURSE_H
