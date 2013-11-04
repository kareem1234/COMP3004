#include "edittask.h"
#include "ui_edittask.h"

EditTask::EditTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditTask)
{
    ui->setupUi(this);
}

void EditTask::setBefore(string type,string date, string desc)
{
    this -> ui-> typeBefore ->setText(QString::fromStdString(type));
    this -> ui-> dateBefore ->setText(QString::fromStdString(date));
    this -> ui-> descBefore ->setText(QString::fromStdString(desc));
}

void EditTask::setAfter(string type,string date, string desc)
{
    this -> ui-> typeAfter ->setText(QString::fromStdString(type));
    this -> ui-> dateAfter ->setText(QString::fromStdString(date));
    this -> ui-> descAfter ->setText(QString::fromStdString(desc));
}

void EditTask::setPass(bool pass){

    if(pass == true){

        this -> ui-> taskEdited ->setText("TRUE");
    }
    else{

        this -> ui-> taskEdited ->setText("FALSE");

    }
}




EditTask::~EditTask()
{
    delete ui;
}
