#include <string>
#include "course.h"


Course::Course()
{
}

std::string Course::tostring(){
    std::string strCourse;
    strCourse = id+" "+courseName +" "+ courseCode +" "
            +courseDescription +" "+ term +" ";
    return strCourse;
}
