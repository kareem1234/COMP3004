#include "TAcontroller.h"

TAcontroller::TAcontroller(QObject *parent) :
    QObject(parent)
{

     connection.start("127.0.0.1",8888);

     this->connect(&taScreen, SIGNAL(cellSelectedSignal(int,int)), this, SLOT(cellSelected(int, int)));
    viewTask();
}


void TAcontroller::viewTask(){

   // vector<Task> t =connection.getTaskListForCourse(mary,courses[0]);

   // taScreen.initTA(email, course);
   // taScreen.setTable(t);
}
void TAcontroller::viewEval(){

   // vector<Task> t =connection.getTaskListForCourse(mary,courses[0]);

    //taScreen.displayEvaluation(connection.getEval(t.at(row)).toString());

}
void TAcontroller::cellSelected(int r, int c){
    row = r;

    ViewEval();
}

string TAcontroller::toString(int a){
    ostringstream ss;
         ss << a;
         return ss.str();
}

