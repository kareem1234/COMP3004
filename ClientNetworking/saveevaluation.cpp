#include "saveevaluation.h"
#include "ui_saveevaluation.h"

SaveEvaluation::SaveEvaluation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveEvaluation)
{
    ui->setupUi(this);
    this->connect(this->ui->createEvaluation,SIGNAL(clicked()),this,SLOT(createEvaluationPressed()));
    this->connect(this->ui->editEvaluation,SIGNAL(clicked()),this,SLOT(editEvaluationPressed()));
    this->connect(this->ui->deleteEvaluation,SIGNAL(clicked()),this,SLOT(deleteEvaluationPressed()));
    ui->editEvaluation->setEnabled(false);
    ui->deleteEvaluation->setEnabled(false);
}

void SaveEvaluation::setEvaluation(string mark, string feedback, string status){

    this -> ui -> taskGrade -> setText(QString::fromStdString(mark));
    this -> ui -> taskFeedback -> setText(QString::fromStdString(feedback));
    this -> ui -> evalStatus -> setText(QString::fromStdString(status));
    ui -> taskGrade -> setText(QString::fromStdString(mark));
    ui -> taskFeedback -> setText(QString::fromStdString(feedback));
    ui -> evalStatus -> setText(QString::fromStdString(status));


}

SaveEvaluation::~SaveEvaluation()
{
    delete ui;
}
void SaveEvaluation:: createEvaluationPressed(){
    emit createEvaluationSignal();
    ui->createEvaluation->setEnabled(false);
    ui->editEvaluation->setEnabled(true);
}

void SaveEvaluation:: editEvaluationPressed(){
    emit editEvaluationSignal();
    ui->editEvaluation->setEnabled(false);
    ui->deleteEvaluation->setEnabled(true);
}
void SaveEvaluation:: deleteEvaluationPressed(){
    emit deleteEvaluationSignal();
    ui->deleteEvaluation->setEnabled(false);
}
