#include "evaluationdialog.h"
#include "ui_evaluationdialog.h"

EvaluationDialog::EvaluationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EvaluationDialog)
{
    ui->setupUi(this);
    deleteButton = ui->deleteButton;
    saveButton = ui->createEval;
    editButton = ui->saveChangesButton;
    comments = ui->comments;
    grade = ui->gradeCombo;
    passLabel = ui->hasEvalTag;
}



EvaluationDialog::~EvaluationDialog()
{
    delete ui;
}

void EvaluationDialog::saveEvaluation(Evaluation *e){

    e->setRating(ui->gradeCombo->currentIndex()+1);
    QString comments = ui->comments->toPlainText();

    e->setComment(comments.toStdString());
    ui->hasEvalTag->setText("True");
    ui->createEval->setEnabled(false);
    ui->deleteButton->setEnabled(true);
    ui->saveChangesButton->setEnabled(true);
}


