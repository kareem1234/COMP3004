#ifndef INSTRUCTORWINDOW_H
#define INSTRUCTORWINDOW_H


#include <QMainWindow>
#include "viewtaskdialog.h"
#include "evaluationdialog.h"
#include <vector>
#include "task.h"
#include"QListWidget"
#include <QPushButton>
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
    void saveEvaluation();
    void deleteEvaluation();
    void deleteTask();
    int getTRow();
    int getCRow();
    void createTaskDialog();
    QListWidget* myList;
    ViewTaskDialog *taskDialog;

private:

    Ui::InstructorWindow *ui;

    EvaluationDialog *evaluationDialog;


signals:

    void logOutInstructor();
    void updateTaskListSignal();
    void updateTAListSignal();
    void saveTaskSignal();
    void deleteEvaluationSignal();
    void saveEvaluationSignal();
    void deleteTaskSignal();


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
