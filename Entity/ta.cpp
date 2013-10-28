#include "ta.h"

TA::TA(){}
TA::TA(TA *aTA){
    setGPA(aTA->getGPA());
    setNewTaskBoolean(aTA->getNewTaskBoolean());
    setFieldOfStudy(aTA->getFieldOfStudy());
    setYearStanding(aTA->getYearStanding());
    setStudentNumber(aTA->getStudentNumber());
    setOfficeRoom(aTA->getOfficeRoom());
}

//set methods
void TA::setGPA(int tempInt)                {  GPA = tempInt;             }
void TA::setNewTaskBoolean(boolean tempBool){  newTask = tempBool;        }
void TA::setFieldOfStudy(String tempString) {  fieldOfStudy = tempString; }
void TA::setYearStanding(int tempInt)       {  yearStanding = tempInt;    }
void TA::setStudentNumber(int tempInt)      {  studentNumber = tempInt;   }
void TA::setOfficeRoom(String tempString)   {  officeRoom = tempString;   }

//get methods
int    TA::getGPA()           {  return GPA ;            }
bool   TA::getNewTaskBoolean(){  return newTask;         }
String TA::getFieldOfStudy()  {  return fieldOfStudy;    }
int    TA::getYearStanding()  {  return yearStanding;    }
int    TA::getStudentNumber() {  return studentNumber;   }
String TA::getOfficeRoom()    {  return officeRoom;      }


//toString method

String TA::toString(){
    String strTA;
    strTA =  "TA's name: "         + name +
             "\nTA's GPA: "        + GPA +
             "\nTA's email: "      + email +
             "\nTA's year stnading: " + yearStanding +
             "\nTA's officeRoom: " + officeRoom +"\n";
    return strTA;
}
