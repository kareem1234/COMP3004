#include <string>
#include <sstream>
#include <stdlib.h>
#include "task.h"

Task::Task()
{
}
Task::Task(std::string line){
    std::stringstream ss;
    std::string tempstring;

    ss << line;

    std::getline(ss, tempstring,' ');
    id = atoi(tempstring.c_str());
    std::getline(ss, tempstring, ' ');
    taID = atoi(tempstring.c_str());
    std::getline(ss, type, ' ');
    std::getline(ss, dueDate, ' ');
    std::getline(ss, instructions, ' ');
    std::getline(ss, progress, ' ');

}
//toString method

std::string Task::toString(){
    std::string strTask;
    std::stringstream ss;
    ss<< id<<" "<<taID <<" "<< type<<" "<< dueDate <<" " << instructions <<" " << progress <<" ";
    strTask =  ss.str();
    return strTask;
}
