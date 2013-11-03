#include "taskcreated.h"
#include "ui_taskcreated.h"
#include <string.h>

using namespace std;

TaskCreated::TaskCreated(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskCreated)
{
    ui->setupUi(this);
}
TaskCreated:: TaskCreated(QWidget *parent,string type,string date, string dsc):
    QDialog(parent),
    ui(new Ui::TaskCreated)
{

    ui->setupUi(this);
    ui->dueDate->setText(QString::fromStdString(type));
    ui->taskType->setText(QString::fromStdString(date));
    ui->taskDescription->setText(QString::fromStdString(dsc));
}

TaskCreated::~TaskCreated()
{
    delete ui;
}
