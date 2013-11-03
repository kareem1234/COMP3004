#include "controller.h"

Controller::Controller(QObject *parent) :
    QObject(parent)
{
    this->connect(&view,SIGNAL(taskCreateTaskButtonPressed()),this,SLOT(createTask()));
    this->connect(&view,SIGNAL(viewCoursesSignal()),this,SLOT(viewCourses()));
    this->connect(&view,SIGNAL(viewTASignal()),this,SLOT(viewTA()));
    this->connect(&view,SIGNAL( viewTasksSignal()),this,SLOT(viewTask()));
    this->connect(&view,SIGNAL( editTaskSignal()),this,SLOT(editTask()));
    this->connect(&view,SIGNAL( saveEvaluationSignal()),this,SLOT(saveEvaluation()));
    this->connect(&view,SIGNAL( createEval()),this,SLOT(createEvaluation()));
    this->connect(&view,SIGNAL( deleteEval()),this,SLOT(deleteEvaluation()));
    this->connect(&view,SIGNAL( editEval()),this,SLOT(editEvaluation()));
     this->connect(&view,SIGNAL( deleteTaskSignal()),this,SLOT(deleteTask()));
}



void Controller::createTask(){

    view.createTask("Jello","PuddingPops","Have you ever taken a jello pudding pop so seriously that you forget your childrens birthdays?");
}

void Controller::viewCourses(){

    string courseNames[5] = {"COMP1","COMP2","COMP3","COMP4","COMP5"};
    view.viewCourses(courseNames,true);

}

void Controller:: createEvaluation(){
    view.evaluationSaveView->setEvaluation("10","cheese","wiz");
}

void Controller:: editEvaluation(){
    view.evaluationSaveView->setEvaluation("5","cheese","biz");
}

void Controller:: deleteEvaluation(){
    view.evaluationSaveView->setEvaluation("","","");
}

void Controller::deleteTask(){

    ///do stuff

}


void Controller::viewTA()
{
    vector<string> TANames;
    view.viewTA(TANames);

}

void Controller:: viewTask(){

    vector<string> taskNames;
    view.viewTasks(taskNames);

}

void Controller::editTask(){
    view.editTask("typeBefore","descBefore","dueDateBefore","typeAfter","descAfter","dueDateAfter",true);
}

void Controller::saveEvaluation(){
    view.saveEvaluation();
}
