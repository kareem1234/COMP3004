#ifndef SAVEEVALUATION_H
#define SAVEEVALUATION_H

#include <QDialog>
#include <string.h>

using namespace std;

namespace Ui {
class SaveEvaluation;
}

class SaveEvaluation : public QDialog
{
    Q_OBJECT
    
public:
    explicit SaveEvaluation(QWidget *parent = 0);
    void setEvaluation(string mark,string feedback,string status);
    ~SaveEvaluation();
    
private:
    Ui::SaveEvaluation *ui;

private slots:
    void createEvaluationPressed();
    void editEvaluationPressed();
    void deleteEvaluationPressed();

signals:
    void createEvaluationSignal();
    void editEvaluationSignal();
    void deleteEvaluationSignal();
};

#endif // SAVEEVALUATION_H
