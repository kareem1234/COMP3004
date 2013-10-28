#include "course.h"

Course::Course()
{
}

String Course::toString(){
    String strCourse;
    strCourse =  "Course name: "          + courseName +
                 "\nCourse Code: "        + courseCode +
                 "\nCourse Description: " + courseDescription +
                 "\nTerm: "               + term;
    return strCourse;
}
