//#include <vector>;
#include <string>;
#include "Instructor.h"
#include "User.h"
#include "TA.h"


Instructor::Instructor(){

}

Instructor::Instructor(std::string dep, std::string office){
    department = dep;
    officeRoom = office;
}

void Instructor::setDepartment(std::string tempstring){
    department = tempstring;
}
void Instructor::setOfficeRoom(std::string tempstring){
    officeRoom = tempstring;
}
std::string Instructor::getOfficeRoom(){
    return officeRoom;
}
std::string Instructor::getDepartment(){
    return department;
}

//overloads. use it by cout << InstructorVariable << endl;

std::string Instructor::tostring(){
    std::string strIns;
    strIns =  "Instructor's name: "         + name +
             " Instructor's department: "   + department +
             " Instructor's officeRoom: "   + officeRoom +"\n";
    return strIns;
}
