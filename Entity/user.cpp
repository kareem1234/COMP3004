#include "user.h"

User::User()
{
}
void User::setName(String tempString){
    name = tempString;
}

void User::setEmail(String tempString){
    email = tempString;
}

void User::setID(int tempInt){
    ID = tempInt;
}

String User::getName( ){
    return name;
}

String User::getEmail( ){
    return email;
}

String User::getID( ){
    return ID;
}
