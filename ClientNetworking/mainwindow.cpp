#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "taskcreated.h"
#include <courses.h>
#include <QtCore>
#include <QtGui>
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    taskView = new TaskView();
    ui->setupUi(this);
    this->connect(this->ui->createTask,SIGNAL(clicked()),this,SLOT(taskCreateSlot()) );
    this->connect(this->ui->viewCourses,SIGNAL(clicked()),this,SLOT(viewCoursesSlot()) );
    this->connect(this->ui->taskEdited, SIGNAL(clicked()), this, SLOT(editTaskSlot()) );
    this->connect(this->ui->evaluation, SIGNAL(clicked()), this, SLOT(saveEvaluationSlot()) );
    this->connect(this->ui->viewTA, SIGNAL(clicked()), this, SLOT(viewTASlot()) );
    this->connect(this->ui->taskView, SIGNAL(clicked()), this, SLOT(viewTasksSlot()) );

}

void MainWindow::createTask(string name, string type, string description){

    TaskCreated *task = new TaskCreated(this, name,type,description);
    task->setModal(true);
    task->exec();

}

void MainWindow::deleteEvaluation(){
    emit deleteEval();
}

void MainWindow:: createEvaluation(){
    emit createEval();
}

void MainWindow::taskCreateSlot(){

    emit taskCreateTaskButtonPressed();
}

void MainWindow::viewCoursesSlot(){

    emit viewCoursesSignal();
}



void MainWindow::viewCourses(string courseNames[5],bool coursesRecieved){


    courseView = new Courses();
    courseView->setModal(true);
    courseView->setLabels(courseNames);
    courseView->setPassTag(coursesRecieved);
    courseView->exec();


}


void MainWindow::viewTASlot()
{

    emit viewTASignal();

}


void MainWindow::viewTA(vector<string> TANames)
{

    TAView = new ViewTA();
    TAView->addTAS(TANames);
    TAView->setModal(true);
    TAView->exec();


}

void MainWindow::viewTasks(vector<string> taskNames){

    taskView = new TaskView();
    this->connect(taskView, SIGNAL(deletePressed()), this, SLOT(deleteTaskSlot()) );
    taskView->addTasks(taskNames);
    taskView->setModal(true);
    taskView->exec();


}

void MainWindow::viewTasksSlot(){

    emit viewTasksSignal();

}


void MainWindow::saveEvaluation(){
    cout<<"made it here"<<endl;
    evaluationSaveView= new SaveEvaluation() ;
    this->connect(evaluationSaveView, SIGNAL(createEvaluationSignal()), this, SLOT(createEvaluation()) );
    this->connect(evaluationSaveView, SIGNAL(deleteEvaluationSignal()), this, SLOT(deleteEvaluation()) );
    this->connect(evaluationSaveView, SIGNAL(editEvaluationSignal()), this, SLOT(editEvaluation()) );
    evaluationSaveView->setModal(true);
    evaluationSaveView->exec();
    cout<<"finished this"<<endl;

}

void MainWindow::saveEvaluationSlot(){
    emit saveEvaluationSignal();
}



void MainWindow::editEvaluation(){

    emit editEval();

}

void MainWindow::editTask(string typeBefore,string descBefore, string dueDateBefore,string typeAfter,string descAfter, string dueDateAfter,bool pass){

    editTaskView =  new EditTask();
    editTaskView->setBefore(typeBefore,dueDateBefore,descBefore);
    editTaskView->setAfter(typeAfter,dueDateAfter, descAfter);
    editTaskView->setPass(pass);
    editTaskView->setModal(true);
    editTaskView->exec();

}

void MainWindow::editTaskSlot(){

    emit editTaskSignal();

}

void MainWindow:: deleteTaskSlot(){
    emit deleteTaskSignal();
}

MainWindow::~MainWindow()
{
    delete ui;
}
