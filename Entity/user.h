#ifndef USER_H
#define USER_H

class User
{
public:
    User();
    void   setName(String);
    void   setEmail(String);
    void   setID(int);
    String getName();
    String getEmail();
    int    getID();
protected:
    int ID;
    String name;
    String email;
};

#endif // USER_H
