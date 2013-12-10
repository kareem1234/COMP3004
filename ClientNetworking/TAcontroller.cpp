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
    this->connect(&taScreen, SIGNAL(reload()), this,SLOT(reloadClicked()));
    taScreen.show();

    currentCourse = client->getCurrentCourse(self);
    updateTaskList();

    viewTask();
}

TAcontroller::~TAcontroller(){
    cout<<"deleted ta"<<endl;
    taScreen.close();
}

void TAcontroller:: logoutClicked(){
    emit logout();
}

void TAcontroller::reloadClicked()
{
    updateTaskList();
    clearDetails();
}

void TAcontroller::updateTaskList()
{
    taskList = client->getTaskListForCourse(self,currentCourse);
    viewTask();
}

void TAcontroller::viewTask(){
   taScreen.initTA(self.getEmail(), currentCourse.getCourseName());

   taScreen.setTable(taskList);
}

void TAcontroller::viewEval(){
    Evaluation eval = client->getEval(taskList[row]);

    if (eval.getId() != -1)
    {
        taScreen.displayEvaluation(QString::number(eval.getRating()), QString::fromStdString(eval.getComment()));
    }
    else
    {
        taScreen.displayEvaluation("N/A", "N/A");
    }
}

void TAcontroller::viewTaskDetails(int row)
{
    Task taskSel = taskList[row];

    taScreen.displayDetails(QString::fromStdString(taskSel.getInstructions()),
                            QString::fromStdString(taskSel.getType()));
}

void TAcontroller::cellSelected(int r, int c) {
    row = r;

    clearDetails();
    viewEval();
    viewTaskDetails(r);
}

void TAcontroller::clearDetails()
{
    taScreen.displayEvaluation("", "");
    taScreen.displayDetails("", "");
}


