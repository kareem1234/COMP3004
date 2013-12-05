#include "evaluationdialog.h"
#include "ui_evaluationdialog.h"

EvaluationDialog::EvaluationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EvaluationDialog)
{
    ui->setupUi(this);
    deleteButton = ui->deleteButton;
    saveButton = ui->saveButton;
}

EvaluationDialog::~EvaluationDialog()
{
    delete ui;
}

void EvaluationDialog:: enableWindow(){


    this->ui->saveButton->setEnabled(true);
    this->ui->deleteButton->setEnabled(true);
    this->ui->remarks->setEnabled(true);
    this->ui->grade->setEnabled(true);
}

void EvaluationDialog::saveEvaluation(){

        QString grade,description;
        grade =1+this->ui->grade->currentIndex();
        description= this->ui->remarks->toPlainText();


}

void EvaluationDialog::deleteEvaluation(){



}
