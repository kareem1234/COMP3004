#include "taskview.h"
#include "ui_taskview.h"

TaskView::TaskView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskView)
{
    ui->setupUi(this);

    this->connect(ui->deleteTaskButton,SIGNAL(clicked()),this,SLOT(deleteButtonSlot()));
}

void TaskView::addTasks(vector<string>  taskNames){

    for(int i = 0 ; i < taskNames.size() ; i++){
        label = new QLabel(QString::fromStdString(taskNames.back()));
        taskNames.pop_back();
        taskLabels.push_back(label);
        ui->verticalLayout->addWidget(label);
    }
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
