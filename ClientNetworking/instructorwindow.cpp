#include "instructorwindow.h"
#include "ui_instructorwindow.h"
#include "task.h"

InstructorWindow::InstructorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InstructorWindow)
{
    ui->setupUi(this);
    this->connect(this->ui->logOut,SIGNAL(clicked()),this,SLOT(logOutSlot()));
    this->connect(this->ui->TAList,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(TAListItemChangedSlot()));
    this->connect(this->ui->courseList,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(courseSelectionChangeSlot()));
    this->connect(this->ui->viewTaskButton,SIGNAL(clicked()),this,SLOT(viewTaskButtonSlot()));
    this->connect(this->ui->taskList,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(activateTaskButtons()));
    this->connect(this->ui->evaluationButton,SIGNAL(clicked()),this,SLOT(evaluationButtonPressed()));
    this->connect(this->ui->deleteTaskButton,SIGNAL(clicked()),this,SLOT(deleteTaskSlot()));
    this->connect(this->ui->taskList,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(taskListSelectionChangedSlot()));
    createTaskButton = ui->createTask;
    myList = ui->taskList;
}

InstructorWindow::~InstructorWindow()
{
    delete ui;
}


void InstructorWindow::TAListItemChangedSlot(){
    ui->taskList->clear();


    emit updateTaskListSignal();

    ui->viewTaskButton->setEnabled(false);
    ui->deleteTaskButton->setEnabled(false);
    ui->evaluationButton->setEnabled(false);
    ui->createTask->setEnabled(true);

}


void InstructorWindow::logOutSlot(){
    emit logOutInstructor();
}


void InstructorWindow::viewTaskButtonSlot(){
    emit viewTaskSignal();


}

void InstructorWindow::saveTaskSignalSlot(){

    emit saveTaskSignal();
}

void InstructorWindow::saveTask(Task* t){

    this->taskDialog->getTaskAtributes(t);
}

void InstructorWindow:: courseSelectionChangeSlot(){


    ui->taskList->clear();

    emit updateTAListSignal();
    ui->viewTaskButton->setEnabled(false);
    ui->deleteTaskButton->setEnabled(false);
    ui->evaluationButton->setEnabled(false);
    ui->createTask->setEnabled(false);
}


int InstructorWindow::getTRow(){
    return ui->TAList->currentRow();
}
int InstructorWindow:: getCRow(){
    return ui->courseList->currentRow();
}

int InstructorWindow::getTaskRow()
{
    return ui->taskList->currentRow();
}

void InstructorWindow:: refreshList(vector<QString> newList,string listType){

    QListWidget *list;
    if(listType == "TA") list = ui->TAList;
    else if(listType == "course") list = ui->courseList;
    else if(listType == "task") list = ui->taskList;



    int size = newList.size();
    list->clear();
    for(int i = 0 ; i < size; i++){
        list->addItem(newList.back());
        newList.pop_back();
    }

}



void InstructorWindow::activateTaskButtons(){

    ui->evaluationButton->setEnabled(true);
    ui->viewTaskButton->setEnabled(true);
    ui->deleteTaskButton->setEnabled(true);

}


void InstructorWindow:: evaluationButtonPressed(){

    emit createEvaluationSignal();

}
void InstructorWindow::saveEvaluationSlot()
{


    emit saveEvaluationSignal();

}

void InstructorWindow::deleteEvaluationSLot(){

    emit deleteEvaluationSignal();

}
void InstructorWindow::saveEvaluation(Evaluation *e){

        evaluationDialog->saveEvaluation(e);

}

void InstructorWindow::deleteEvaluation(){

}

void InstructorWindow::deleteTask(){

    int i = ui->taskList->currentRow();
    this->ui->taskList->takeItem(i);

}


void InstructorWindow::deleteTaskSlot(){
    emit deleteTaskSignal();
}

void InstructorWindow:: taskListSelectionChangedSlot(){
    ui->createTask->setEnabled(false);

}

void InstructorWindow::createTaskDialog(){
    taskDialog= new ViewTaskDialog();
    taskDialog->createTask->setText("Create Task");
    connect(this->taskDialog,SIGNAL(saveChanges()),this,SLOT(saveTaskSignalSlot()));

    taskDialog->show();
}


void InstructorWindow::disableButtons()
{
    ui->deleteTaskButton->setEnabled(false);
    ui->viewTaskButton->setEnabled(false);
    ui->evaluationButton->setEnabled(false);

}

void InstructorWindow::updateEmailLabel(QString email)
{
    ui->labelEmail->setText(email);
}
