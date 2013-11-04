#include "viewtasks.h"
#include "ui_viewtasks.h"


ViewTasks::ViewTasks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTasks)
{

    ui->setupUi(this);


}

void ViewTasks::addTasks(vector<string>  taskNames){
    int size = taskNames.size();
    for(int i = 0 ; i < size ; i++){
        label = new QLabel(QString::fromStdString(taskNames.back()));
        taskNames.pop_back();
        taskLabels.push_back(label);
        ui->verticalLayout->addWidget(label);
    }
}


void ViewTasks::deleteTask(){

    label = taskLabels.back();
    taskLabels.pop_back();
    label->hide();

}

ViewTasks::~ViewTasks()
{
    delete ui;
}
