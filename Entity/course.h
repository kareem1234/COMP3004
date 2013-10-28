#ifndef COURSE_H
#define COURSE_H

class Course
{
public:
    Course();
    String toString();
private:
    String courseName;
    String courseCode;
    String courseDescription;
    String term;
    //This isnt the right synta
    //Date meetingTime
};

#endif // COURSE_H
