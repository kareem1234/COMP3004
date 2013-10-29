#include <string>
#include "course.h"


Course::Course()
{
}

Course::Course(std::string line){
    std::stringstream ss;
    std::string tempstring;
    ss << line;
    std::getline(ss, tempstring, ' ');
    id = atoi(tempstring.c_str());
    std::getline(ss, courseName, ' ');
    std::getline(ss, courseCode, ' ');
    std::getline(ss, courseDescription, ' ');
    std::getline(ss, term,  ' ');

 }
 //toString method

 std::string Course::toString(){
      std::string strCourse;
      std::stringstream ss;
     ss<< id<<" "<< courseName <<" "<< courseCode<<" "<< courseDescription <<" " << term <<" ";
   strCourse =  ss.str();
      return strCourse;
  }


