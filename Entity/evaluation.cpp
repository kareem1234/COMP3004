#include "evaluation.h"

Evaluation::Evaluation()
{
}
String Evaluation::toString(){
    String strEval;
    strEval =  "Evaluation Rating: "         + rating +
             "\nEvaluation comment: "        + comment ;
    return strEval;


}
