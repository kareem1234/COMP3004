#include <string>
#include <sstream>
#include <stdlib.h>
#include "evaluation.h"


Evaluation::Evaluation()
{
}
Evaluation::Evaluation(std::string line){
    std::stringstream ss;
    std::string tempstring;
    ss << line;
    std::getline(ss, tempstring,' ');
    id = atoi(tempstring.c_str());
    std::getline(ss, tempstring, ' ');
    taskID = atoi(tempstring.c_str());
    std::getline(ss, tempstring, ' ');
    rating = atoi(tempstring.c_str());
    std::getline(ss, comment, ' ');

}
//toString method

std::string Evaluation::toString(){
    std::string strCourse;
    std::stringstream ss;
    ss<< id<<" "<< taskID <<" "<< rating<<" "<< comment <<" ";
    strCourse =  ss.str();
    return strCourse;


}
