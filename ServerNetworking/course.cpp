#include <string>
#include "course.h"


Course::Course()
{
}

Course::Course(int tempId, std::string cName, std::string cCode, std::string cDes,
               std::string mTime, std::string tempTerm){
    id = tempId;
    courseName = cName;
    courseCode = cCode;
    courseDescription = cDes;
    meetingTime = mTime;
    term = tempTerm;

}

Course::Course(std::string line){
    std::stringstream ss;
    std::string tempstring;
    ss << line;
    std::getline(ss, tempstring, '*');        //id
    id = atoi(tempstring.c_str());
    std::getline(ss, courseName, '*');        //courseName
    std::getline(ss, courseCode, '*');        //courseCode
    std::getline(ss, courseDescription, '*'); //courseDescription
    std::getline(ss, term,  '*');             //term

 }

void Course::setId(int tempInt){id = tempInt; }
void Course::setCourseName(std::string tempstring){ courseName=tempstring;}
void Course::setCourseCode(std::string tempstring){ courseCode=tempstring;}
void Course::setCourseDescription(std::string tempstring){ courseDescription=tempstring;}
void Course::setMeetingTime(std::string tempstring){ meetingTime=tempstring;}
void Course::setTerm(std::string tempstring){ term=tempstring; }

int         Course::getId()          { return id;          }
std::string Course::getCourseName(){ return courseName;}
std::string Course::getCourseCode(){ return courseCode;}
std::string Course::getCourseDescription(){ return courseDescription;}
std::string Course::getMeetingTime(){ return meetingTime;}
std::string Course::getTerm(){ return term ;}

 //toString method

 std::string Course::toString(){
      std::string strCourse;
      std::stringstream ss;
     ss<< id<<"*"<< courseName <<"*"<< courseCode<<"*"<< courseDescription <<"*" << term <<"*";
   strCourse =  ss.str();
      return strCourse;
  }


