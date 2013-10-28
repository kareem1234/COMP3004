#include <string>
#include "course.h"


Course::Course()
{
}

std::string Course::tostring(){
    std::string strCourse;
    strCourse =  "Course name: "          + courseName +
                 " Course Code: "        + courseCode +
                 " Course Description: " + courseDescription +
            " Term: "               + term +"\n";
    return strCourse;
}
