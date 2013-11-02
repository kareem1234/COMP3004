#include <string>
#include <sstream>
#include <stdlib.h>
#include "user.h"

User::User()
{
}
User::User(int tempID, std::string tempName,std::string tempEmail){
    id = tempID;
    name = tempName;
    email = tempEmail;
}

User::User(std::string line){
    std::stringstream ss;
    std::string tempstring;

    ss << line;
    std::getline(ss, tempstring,'*');    //id
    id = atoi(tempstring.c_str());
    std::getline(ss, name, '*');         //name
    std::getline(ss, email,'*');         //email
}
//set methods
void User::setName  (std::string tempstring){ name = tempstring;    }
void User::setEmail (std::string tempstring){ email = tempstring;   }
void User::setId    (int tempInt)           { id = tempInt;         }

//get methods
std::string User::getName() {    return name;   }
std::string User::getEmail(){    return email;  }
int         User::getId()   {    return id;     }
