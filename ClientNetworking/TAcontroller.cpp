#include "TAcontroller.h"

TAcontroller::TAcontroller(taClient* c, TA t,QObject *parent) :
    QObject(parent)
{
    self = t;
    client = c;
    this->connect(&taScreen, SIGNAL(cellSelectedSignal(int,int)), this, SLOT(cellSelected(int, int)));
    viewTask();
}


void TAcontroller::viewTask(){
   Course c = client->getCurrentCourse(self);
   vector<Task> t = client->getTaskListForCourse(self,c);
   taScreen.initTA(self.getEmail(), c.toString());
   taScreen.setTable(t);
}
void TAcontroller::viewEval(){

    Course c = client->getCurrentCourse(self);
    vector<Task> t = client->getTaskListForCourse(self,c);
    taScreen.displayEvaluation(client->getEval(t[row]).toString());

}
void TAcontroller::cellSelected(int r, int c){
    row = r;

    viewEval();
}


