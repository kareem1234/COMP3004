#include <string>
#include <sstream>
#include "evaluation.h"


Evaluation::Evaluation()
{
}
std::string Evaluation::toString(){
    std::string strEval;
    std::stringstream ss;
    ss  <<id<<" "<< rating <<" "<< comment <<" ";
    strEval = ss.str();
    return strEval;


}
