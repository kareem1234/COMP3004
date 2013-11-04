#include "taskview.h"
#include "ui_taskview.h"
#include <iostream>
TaskView::TaskView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskView)
{
    ui->setupUi(this);

    this->connect(ui->deleteTaskButton,SIGNAL(clicked()),this,SLOT(deleteButtonSlot()));
}

void TaskView::addTasks(vector<string>  taskNames){
    cout<<"length is: "<< taskNames.size()<<endl;
    int length = taskNames.size();
    for(int i = 0 ; i < length; i++){
        cout<<i<<endl;
        label = new QLabel(QString::fromStdString(taskNames.back()));
        taskNames.pop_back();
        taskLabels.push_back(label);
        ui->verticalLayout->addWidget(label);
    }
    cout<<"task label size"<<taskLabels.size()<<endl;
}


void TaskView::deleteTask(){
   if(taskLabels.size() != 0)
    {
        label = taskLabels.back();
        taskLabels.pop_back();
        label->hide();
    }
}

TaskView::~TaskView()
{
    delete ui;
}

void TaskView::deleteButtonSlot(){

    emit deletePressed();
    deleteTask();

}
