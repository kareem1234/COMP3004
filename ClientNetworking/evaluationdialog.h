#ifndef EVALUATIONDIALOG_H
#define EVALUATIONDIALOG_H

#include <QDialog>

namespace Ui {
class EvaluationDialog;
}

class EvaluationDialog : public QDialog
{
    Q_OBJECT
    
public:
    void enableWindow();
    explicit EvaluationDialog(QWidget *parent = 0);
    void saveEvaluation();
    void deleteEvaluation();

    ~EvaluationDialog();
    QPushButton *deleteButton;
    QPushButton *saveButton;
    
private:
    Ui::EvaluationDialog *ui;
signals:
    void deleteButtonPressed();
};

#endif // EVALUATIONDIALOG_H
