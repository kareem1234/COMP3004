#include <string>
#include <sstream>
#include <stdlib.h>
#include "evaluation.h"


Evaluation::Evaluation()
{
}
Evaluation::Evaluation(int tempRating, int tempID, int tempTaskID, std::string tempComment){
    rating = tempRating;
    id = tempID;
    taskID = tempTaskID;
    comment = tempComment;
}

Evaluation::Evaluation(std::string line){
    std::stringstream ss;
    std::string tempstring;
    ss << line;
    std::getline(ss, tempstring,' ');     //id
    id = atoi(tempstring.c_str());
    std::getline(ss, tempstring, ' ');    //taskID
    taskID = atoi(tempstring.c_str());
    std::getline(ss, tempstring, ' ');    //rating
    rating = atoi(tempstring.c_str());
    std::getline(ss, comment, ' ');       //comment

}

//set methods
void Evaluation::setRating  (int tempInt)           { rating = tempInt;     }
void Evaluation::setId      (int tempInt)           { id = tempInt;         }
void Evaluation::setTaskId  (int tempInt)           { taskID = tempInt;     }
void Evaluation::setComment (std::string tempstring){ comment = tempstring; }

//get methods
int Evaluation::getRating()         { return rating; }
int Evaluation::getId()             { return id;     }
int Evaluation::getTaskId()         { return taskID; }
std::string Evaluation::getComment(){ return comment;}

//toString method

std::string Evaluation::toString(){
    std::string strCourse;
    std::stringstream ss;
    ss<< id<<" "<< taskID <<" "<< rating<<" "<< comment <<" ";
    strCourse =  ss.str();
    return strCourse;



}
