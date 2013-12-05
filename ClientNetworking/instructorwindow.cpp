#include "instructorwindow.h"
#include "ui_instructorwindow.h"

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
}

InstructorWindow::~InstructorWindow()
{
    delete ui;
}


void InstructorWindow::TAListItemChangedSlot(){



    ui->taskList->clear();

    QString name = this->ui->TAList->currentItem()->text();
    this->ui->TASelectedLabel->setText(name);

    emit updateTaskListSignal();

    ui->viewTaskButton->setEnabled(false);
    ui->deleteTaskButton->setEnabled(false);
    ui->evaluationButton->setEnabled(false);

}


void InstructorWindow::logOutSlot(){
    emit logOutInstructor();
}


void InstructorWindow::viewTaskButtonSlot(){

    taskDialog = new ViewTaskDialog();
    taskDialog->setModal(true);
    connect(taskDialog,SIGNAL(saveChanges()),this,SLOT(saveTaskSignalSlot()));
    taskDialog->exec();

}

void InstructorWindow::saveTaskSignalSlot(){

    emit saveTaskSignal();
    //change the get Task attributes in tsk Dialog
    this->taskDialog->getTaskAtributes();
}

void InstructorWindow::saveTask(){

    this->taskDialog->getTaskAtributes();
}

void InstructorWindow:: courseSelectionChangeSlot(){


    ui->taskList->clear();

    emit updateTAListSignal();
    ui->viewTaskButton->setEnabled(false);
    ui->deleteTaskButton->setEnabled(false);
    ui->evaluationButton->setEnabled(false);
}


int InstructorWindow::getTRow(){
    return ui->TAList->currentRow();
}
int InstructorWindow:: getCRow(){
    return ui->courseList->currentRow();
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
    evaluationDialog= new EvaluationDialog();
    this->connect(evaluationDialog->deleteButton,SIGNAL(clicked()),this,SLOT(deleteEvaluationSLot()));
    this->connect(evaluationDialog->saveButton,SIGNAL(clicked()),this,SLOT(saveEvaluationSlot()));
    evaluationDialog->show();

}
void InstructorWindow::saveEvaluationSlot()
{

    emit saveEvaluationSignal();

}

void InstructorWindow::deleteEvaluationSLot(){

    emit deleteEvaluationSignal();

}
void InstructorWindow::saveEvaluation(){

        evaluationDialog->saveEvaluation();

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
