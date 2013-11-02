//#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "instructor.h"
#include "user.h"
#include "ta.h"


Instructor::Instructor(){

}
Instructor::Instructor(std::string line){

    std::stringstream ss;
    std::string tempstring;
    ss << line;
    std::getline(ss, tempstring, ' ');
    id = atoi(tempstring.c_str());
    std::getline(ss, name,' ');
    std::getline(ss, email, ' ');
    std::getline(ss, officeRoom, ' ');
    std::getline(ss, department, ' ');

}


//set methods
void Instructor::setDepartment(std::string tempstring){  department = tempstring;}
void Instructor::setOfficeRoom(std::string tempstring){  officeRoom = tempstring;}

//get methods
std::string Instructor::getOfficeRoom() { return officeRoom;    }
std::string Instructor::getDepartment() { return department;    }

//toString method

std::string Instructor::toString(){
    std::string strInstructor;
    std::stringstream ss;

    ss << id << " " << name << " " << email << " " << officeRoom << " " << department;
    strInstructor =  ss.str();

    return strInstructor;
}
