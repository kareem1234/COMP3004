#ifndef INSTRUCTORWINDOW_H
#define INSTRUCTORWINDOW_H


#include <QMainWindow>
#include "viewtaskdialog.h"
#include "evaluationdialog.h"
#include <vector>
#include "task.h"
#include"QListWidget"
#include <QPushButton>
#include "evaluation.h"
using namespace std;


namespace Ui {
class InstructorWindow;
}

class InstructorWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit InstructorWindow(QWidget *parent = 0);
    ~InstructorWindow();

    QPushButton *createTaskButton;
    void refreshList(vector<QString> newList,string listType);
    void saveTask(Task * t);
    void saveEvaluation(Evaluation *e);
    void deleteEvaluation();
    void deleteTask();
    int getTRow();
    int getCRow();
    int getTaskRow();
    void createTaskDialog();

    void updateEmailLabel(QString email);
    void disableButtons();

    QListWidget* myList;
    EvaluationDialog *evaluationDialog;
    ViewTaskDialog *taskDialog;

private:

    Ui::InstructorWindow *ui;




signals:

    void logOutInstructor();
    void updateTaskListSignal();
    void updateTAListSignal();
    void saveTaskSignal();
    void deleteEvaluationSignal();
    void saveEvaluationSignal();
    void deleteTaskSignal();
    void viewTaskSignal();
    void createEvaluationSignal();


private slots:

    void taskListSelectionChangedSlot();
    void courseSelectionChangeSlot();
    void logOutSlot();
    void TAListItemChangedSlot();
    void viewTaskButtonSlot();
    void activateTaskButtons();
    void saveTaskSignalSlot();  
    void evaluationButtonPressed();
    void saveEvaluationSlot();
    void deleteEvaluationSLot();
    void deleteTaskSlot();

};

#endif // INSTRUCTORWINDOW_H
