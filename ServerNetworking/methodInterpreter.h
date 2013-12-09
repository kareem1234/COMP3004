#ifndef METHODINTERPRETER_H
#define METHODINTERPRETER_H
#include "Message.cpp"
#include <iostream>
using namespace std;

class MethodInterpreter{

    public:
            MethodInterpreter(string m);
            bool isTA();

    private:
           string msg;

};



#endif // METHODINTERPRETER_H
