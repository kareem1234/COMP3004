#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>

class Course
{
public:
    Course();
    Course(std::string);

    void setId(int);
    void setCourseName(std::string);
    void setCourseCode(std::string);
    void setCourseDescription(std::string);
    void setMeetingTime(std::string);
    void setTerm(std::string);

    int getId();
    std::string getCourseName();
    std::string getCourseCode();
    std::string getCourseDescription();
    std::string getMeetingTime();
    std::string getTerm();


    std::string toString();

private:
    int id;
    std::string courseName;
    std::string courseCode;
    std::string courseDescription;
    std::string meetingTime;
    std::string term;

};

#endif // COURSE_H
