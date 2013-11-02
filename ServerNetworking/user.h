#ifndef USER_H
#define USER_H
#include <string>
class User
{
public:
    User();
    User(std::string);
    void   setName(std::string);
    void   setEmail(std::string);
    void   setID(int);
    std::string getName();
    std::string getEmail();
    int         getID();
protected:
    int id;
    std::string name;
    std::string email;
};

#endif // USER_H
