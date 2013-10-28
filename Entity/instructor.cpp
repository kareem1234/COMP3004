//#include <vector>;

#include "Instructor.h"
#include "User.h"
#include "TA.h"
using namespace std;

Instructor::Instructor(){

}

Instructor::Instructor(String dep, String office){
    department = dep;
    officeRoom = office;
}

void Instructor::setDepartment(String tempString){
    department = tempString;
}
void Instructor::setOfficeRoom(String tempString){
    officeRoom = tempString;
}
String Instructor::getOfficeRoom(){
    return officeRoom;
}
String Instructor::getDepartment(){
    return department;
}

//overloads. use it by cout << InstructorVariable << endl;

String Instructor::toString(){
    String strIns;
    strIns =  "TA's name: "         + name +
             "\nTA's GPA: "        + GPA +
             "\nTA's email: "      + email +
             "\nTA's year stnading: " + yearStanding +
             "\nTA's officeRoom: " + officeRoom +"\n";
    return strIns;
}
