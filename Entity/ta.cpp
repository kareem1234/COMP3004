#include <sstream>
#include <iostream>
#include <stdlib.h>
#include "ta.h"


TA::TA(){}
TA::TA(int tempID, int tempCourseID, std::string tempName,int tempGPA,
       std::string tempEmail, int tempYear, std::string tempOffice,
       int tempStudentNumber, std::string tempStudy){

    id = tempID;
    courseID = tempCourseID;
    name = tempName;
    gpa = tempGPA;
    email = tempEmail;
    yearStanding = tempYear;
    officeRoom = tempOffice;
    studentNumber = tempStudentNumber;
    fieldOfStudy = tempStudy;
}

TA::TA(std::string line){
    std::stringstream ss;
    std::string tempstring;

    ss << line;
    std::getline(ss, tempstring,' ');       //id
    id = atoi(tempstring.c_str());
    std::getline(ss, tempstring, ' ');      //courseID;
    courseID = atoi(tempstring.c_str());
    std::getline(ss, name, ' ');            //name
    std::getline(ss, tempstring,' ');       //gpa
    gpa = atoi(tempstring.c_str());
    std::getline(ss, email, ' ');           //email
    std::getline(ss, tempstring,' ');       //yearStanding
    yearStanding = atoi(tempstring.c_str());
    std::getline(ss, officeRoom, ' ' );     //officeRoom
    std::getline(ss, tempstring,' ');       //studentNumber
    studentNumber = atoi(tempstring.c_str());
    std::getline(ss, fieldOfStudy, ' ');    //fieldOfStudy


}


//set methods
void TA::setCourseId        (int         tempInt)    {  courseID = tempInt;        }
void TA::setGPA             (int         tempInt)    {  gpa = tempInt;             }
void TA::setYearStanding    (int         tempInt)    {  yearStanding = tempInt;    }
void TA::setStudentNumber   (int         tempInt)    {  studentNumber = tempInt;   }
void TA::setFieldOfStudy    (std::string tempstring) {  fieldOfStudy = tempstring; }
void TA::setOfficeRoom      (std::string tempstring) {  officeRoom = tempstring;   }


//get methods
int         TA::getCourseId()      {  return courseID;        }
int         TA::getGPA()           {  return gpa ;            }
int         TA::getYearStanding()  {  return yearStanding;    }
int         TA::getStudentNumber() {  return studentNumber;   }
std::string TA::getOfficeRoom()    {  return officeRoom;      }
std::string TA::getFieldOfStudy()  {  return fieldOfStudy;    }

//toString method

std::string TA::toString(){
    std::string strTA;
    std::stringstream ss;

    ss << id << " "<< courseID << " "<< name << " " << gpa <<" "<< email << " "
       << yearStanding <<" " << officeRoom << " " << studentNumber <<" "<< fieldOfStudy <<" ";

    strTA =  ss.str();

    return strTA;
}
