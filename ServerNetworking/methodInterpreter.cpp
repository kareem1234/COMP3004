#include "methodInterpreter.h"

MethodInterpreter::MethodInterpreter(string m){
     msg =m;

}

bool MethodInterpreter::isTA(){
    string method = Message<string,int>::getMethod(msg);

    if(method.compare(Message<string,int>::saveTask) == 0 )
        return false;

    else if(method.compare(Message<string,int>::deleteTask) == 0 )
        return false;

    else if(method.compare(Message<string,int>::saveEval)== 0)
        return false;

    else if(method.compare(Message<string,int>::deleteEval) == 0)
        return false;

    else if(method.compare(Message<string,int>::getEval)==0)
        return false;

    else if(method.compare(Message<string,int>::viewTaskListForCourse)==0)
        return true;


    else if(method.compare(Message<string,int>::viewTaList)==0)
        return false;

    else if(method.compare(Message<string,int>::viewCourseList)==0)
                return false;

    else if (method.compare(Message<string,int>::getTa)==0)
                return true;


    else if (method.compare(Message<string,int>::getInstructor)==0)
        return false;


   else if (method.compare(Message<string,int>::getCurrentCourse)==0)
        return true;



}
