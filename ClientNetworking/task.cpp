#include <string>
#include "task.h"

Task::Task()
{
}
std::string Task::toString(){
    std::string strTask;
    strTask = ID+" "+type +
             " "+ dueDate +
             " "+ instructions +
            " " + progress +" ";
    return strTask;
}
