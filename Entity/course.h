#ifndef COURSE_H
#define COURSE_H

class Course
{
public:
    Course();
    std::string tostring();
private:
    std::string courseName;
    std::string courseCode;
    std::string courseDescription;
    std::string term;
    //This isnt the right synta
    //Date meetingTime
};

#endif // COURSE_H
