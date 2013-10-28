#include <string>
#include <sstream>
#include "evaluation.h"


Evaluation::Evaluation()
{
}
std::string Evaluation::tostring(){
    std::string strEval;
    std::stringstream ss;
    ss << "Evaluation Rating: "        << rating <<
            "Evaluation comment: "        << comment <<"\n";
    strEval = ss.str();
    return strEval;


}
