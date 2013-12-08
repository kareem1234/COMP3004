#include "TAcontroller.h"
#include <iostream>
TAcontroller::TAcontroller(taClient* c, TA t,QObject *parent) :
    QObject(parent)
{
    cout<<"t is: "<<t.toString()<<endl;
    self = t;
    client = c;
    this->connect(&taScreen, SIGNAL(cellSelectedSignal(int,int)), this, SLOT(cellSelected(int, int)));
    this->connect(&taScreen, SIGNAL(logout()), this,SLOT(logoutClicked()));
    taScreen.show();
    viewTask();
}

TAcontroller::~TAcontroller(){
    taScreen.close();
}

void TAcontroller:: logoutClicked(){
    emit logout();
}

void TAcontroller::viewTask(){
   Course c = client->getCurrentCourse(self);
   cout<<"course Name is: "<<c.toString()<<endl;
   vector<Task> t = client->getTaskListForCourse(self,c);
   taScreen.initTA(self.getEmail(), c.getCourseName());
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


