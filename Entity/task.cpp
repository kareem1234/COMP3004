#include "task.h"

Task::Task()
{
}
String Task::toString(){
    String strTask;
    strTask =  "Task Type: "         + type +
             "\nTask Due Date: "        + dueDate +
             "\nTask Instructions: "      + instructions +
             "\nTask Progress: " + progress ;
    return strTask;
}
