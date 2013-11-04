//#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "instructor.h"
#include "user.h"
#include "ta.h"


Instructor::Instructor(){

}
Instructor::Instructor(int tempID, std::string tempName, std::string tempEmail,
                       std::string tempOffice, std::string tempDep){
    id = tempID;
    name = tempName;
    email = tempEmail;
    officeRoom = tempOffice;
    department = tempDep;


}

Instructor::Instructor(std::string line){

    std::stringstream ss;
    ss<<line;
    std::string tempstring;
    std::getline(ss, tempstring, '*');     //id
    id = atoi(tempstring.c_str());
    std::getline(ss, name,'*');            //name
    std::getline(ss, email, '*');          //email
    std::getline(ss, officeRoom, '*');     //officeRoom
    std::getline(ss, department, '*');     //department

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

    ss << id << "*" << name << "*" << email << "*" << officeRoom << "*" << department;
    strInstructor =  ss.str();

    return strInstructor;
}
