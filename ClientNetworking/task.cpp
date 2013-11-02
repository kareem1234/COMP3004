#include <string>
#include <sstream>
#include <stdlib.h>
#include "task.h"

Task::Task(){}
Task::Task(int tempId, int tempTAID, int tempCourseID, std::string tempType,
           std::string tempDate, std::string tempIns, std::string tempProgress){

    id = tempId;
    taID = tempTAID;
    courseId = tempCourseID;
    type = tempType;
    dueDate = tempDate;
    instructions = tempIns;
    progress = tempProgress;

}

Task::Task(std::string line){
    std::stringstream ss;
    std::string tempstring;

    ss << line;

    std::getline(ss, tempstring,'*');
    id = atoi(tempstring.c_str());
    std::getline(ss, tempstring, '*');
    taID = atoi(tempstring.c_str());
    std::getline(ss, type, '*');
    std::getline(ss, dueDate, '*');
    std::getline(ss, instructions, '*');
    std::getline(ss, progress, '*');

}

//set methods
void Task::setId          (int tempInt)           { id = tempInt;             }
void Task::setTaId        (int tempInt)           { taID = tempInt;           }
void Task::setCourseId    (int tempInt)           { courseId = tempInt;       }
void Task::setType        (std::string tempstring){ type = tempstring;        }
void Task::setDueDate     (std::string tempstring){ dueDate = tempstring;     }
void Task::setInstructions(std::string tempstring){ instructions = tempstring;}
void Task::setProgress    (std::string tempstring){ progress = tempstring;    }

//get methods

int         Task::getId()          { return id;          }
int         Task::getTaId()        { return taID;        }
int         Task::getCourseId()    { return courseId;    }
std::string Task::getType()        { return type;        }
std::string Task::getDueDate()     { return dueDate;     }
std::string Task::getInstructions(){ return instructions;}
std::string Task::getProgress()    { return progress;    }

//toString method
std::string Task::toString(){

    std::string strTask;
    std::stringstream ss;

    ss << id << "*"<< taID << "*"<< type <<"*"<< dueDate << "*"
       << instructions << "*" << progress << "*";

    strTask =  ss.str();

    return strTask;
}
