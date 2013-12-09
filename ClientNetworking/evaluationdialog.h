#ifndef EVALUATIONDIALOG_H
#define EVALUATIONDIALOG_H

#include <QDialog>
#include "evaluation.h"
#include <QComboBox>
#include <QTextEdit>
#include <QLabel>


namespace Ui {
class EvaluationDialog;
}

class EvaluationDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit EvaluationDialog(QWidget *parent = 0);
    QPushButton *deleteButton;
    QPushButton *saveButton;
    QPushButton *editButton;
    QComboBox *grade;
    QTextEdit *comments;
    QLabel *passLabel;


    void saveEvaluation(Evaluation *e);
    ~EvaluationDialog();
    
private:
    Ui::EvaluationDialog *ui;
};

#endif // EVALUATIONDIALOG_H
