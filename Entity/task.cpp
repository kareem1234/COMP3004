#include <string>
#include "task.h"

Task::Task()
{
}
std::string Task::tostring(){
    std::string strTask;
    strTask =  "Task Type: "         + type +
             "\nTask Due Date: "        + dueDate +
             "\nTask Instructions: "      + instructions +
             "\nTask Progress: " + progress ;
    return strTask;
}
