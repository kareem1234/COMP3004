#include "user.h"
#include <string>

User::User()
{
}
void User::setName(std::string tempstring){
    name = tempstring;
}

void User::setEmail(std::string tempstring){
    email = tempstring;
}

void User::setID(int tempInt){
    ID = tempInt;
}

std::string User::getName(){
    return name;
}

std::string User::getEmail(){
    return email;
}

int User::getID(){
    return ID;
}
