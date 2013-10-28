#include <sstream>
#include "ta.h"
//#include <QString>

TA::TA(){}
/*
TA::TA(TA &aTA){
    setGPA(aTA->getGPA());
    setNewTaskBoolean(aTA->getNewTaskBoolean());
    setFieldOfStudy(aTA->getFieldOfStudy());
    setYearStanding(aTA->getYearStanding());
    setStudentNumber(aTA->getStudentNumber());
    setOfficeRoom(aTA->getOfficeRoom());
}
*/
//set methods
void TA::setGPA(int tempInt)                    {  GPA = tempInt;             }
void TA::setNewTaskBoolean(bool tempBool)       {  newTask = tempBool;        }
void TA::setFieldOfStudy(std::string tempstring){  fieldOfStudy = tempstring; }
void TA::setYearStanding(int tempInt)           {  yearStanding = tempInt;    }
void TA::setStudentNumber(int tempInt)          {  studentNumber = tempInt;   }
void TA::setOfficeRoom(std::string tempstring)  {  officeRoom = tempstring;   }

//get methodsbool
bool        TA::getNewTaskBoolean(){  return newTask;         }
int         TA::getGPA()           {  return GPA ;            }
int         TA::getYearStanding()  {  return yearStanding;    }
int         TA::getStudentNumber() {  return studentNumber;   }
std::string TA::getOfficeRoom()    {  return officeRoom;      }
std::string TA::getFieldOfStudy()  {  return fieldOfStudy;    }

//tostring method

std::string TA::tostring(){
    std::string strTA;
    std::stringstream ss;
    ss << "TA's name: "         << name <<
          " TA's GPA: "        << GPA<<
          " TA's email: "      << email <<
          " TA's year stnading: " << yearStanding <<
          " TA's officeRoom: " << officeRoom <<"\n";
    strTA =  ss.str();
    return strTA;
    /*strTA =  ("TA's name: "         + name +
             " TA's GPA: "        + QString::number(GPA) +
             " TA's email: "      + email +
             " TA's year stnading: " + yearStanding +
             " TA's officeRoom: " + officeRoom +"\n");
    return strTA;*/
}
