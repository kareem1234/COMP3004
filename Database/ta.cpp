#include <sstream>
#include <iostream>
#include <stdlib.h>
#include "ta.h"


TA::TA(){}
TA::TA(std::string line){
    std::stringstream ss;
    std::string tempstring;

    ss << line;
    std::getline(ss, tempstring,' ');
    id = atoi(tempstring.c_str());
    std::getline(ss, name, ' ');
    std::getline(ss, tempstring,' ');
    gpa = atoi(tempstring.c_str());
    std::getline(ss, email, ' ');
    std::getline(ss, tempstring,' ');
    yearStanding = atoi(tempstring.c_str());
    std::getline(ss, officeRoom, ' ' );
    std::getline(ss, tempstring,' ');
    studentNumber = atoi(tempstring.c_str());
    std::getline(ss, fieldOfStudy, ' ');
    //std::getline(ss, newTask, ' ');


}


//set methods
void TA::setGPA             (int         tempInt)    {  gpa = tempInt;             }
void TA::setYearStanding    (int         tempInt)    {  yearStanding = tempInt;    }
void TA::setStudentNumber   (int         tempInt)    {  studentNumber = tempInt;   }
void TA::setFieldOfStudy    (std::string tempstring) {  fieldOfStudy = tempstring; }
void TA::setOfficeRoom      (std::string tempstring) {  officeRoom = tempstring;   }


//get methods
int         TA::getGPA()           {  return gpa ;            }
int         TA::getYearStanding()  {  return yearStanding;    }
int         TA::getStudentNumber() {  return studentNumber;   }
std::string TA::getOfficeRoom()    {  return officeRoom;      }
std::string TA::getFieldOfStudy()  {  return fieldOfStudy;    }

//toString method

std::string TA::toString(){
    std::string strTA;
    std::stringstream ss;

    ss << id << " "<< name << " " << gpa <<" "<< email << " " << yearStanding
       <<" " << officeRoom << " " << studentNumber <<" "<< fieldOfStudy <<" ";

    strTA =  ss.str();

    return strTA;
}
