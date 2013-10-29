#ifndef COURSE_H
#define COURSE_H

class Course
{
public:
    Course();
    Course(std::string);
    std::string toString();
private:
    int id;
    std::string courseName;
    std::string courseCode;
    std::string courseDescription;
    std::string term;
    std::string meetingTime;
};

#endif // COURSE_H
