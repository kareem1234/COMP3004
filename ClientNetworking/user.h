#ifndef USER_H
#define USER_H
#include <string>

class User
{
public:
    User();
    User(std::string);

    //set method
    void   setName(std::string);
    void   setEmail(std::string);
    void   setId(int);

    //get method
    int         getId();
    std::string getName();
    std::string getEmail();

protected:
    int id;
    std::string name;
    std::string email;
};

#endif // USER_H
