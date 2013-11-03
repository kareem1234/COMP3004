#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "taskcreated.h"
#include <courses.h>
#include <edittask.h>
#include <saveevaluation.h>
#include <taskview.h>
#include <viewta.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createTask(string name, string type, string desc);
    void viewCourses(string courseNames[5],bool coursesRecieved);
    void viewTA(vector<string> TANames);
    void viewTasks(vector<string> taskNames);
    void editTask(string typeBefore,string descBefore, string dueDateBefore,string typeAfter,string descAfter, string dueDateAfter,bool pass);
    void saveEvaluation();
    TaskView *taskView;
    Courses *courseView;
    EditTask *editTaskView;
    ViewTA *TAView;
    SaveEvaluation *evaluationSaveView;



private slots:
    void taskCreateSlot();
    void viewCoursesSlot();
    void editTaskSlot();
    void saveEvaluationSlot();
    void viewTasksSlot();
    void viewTASlot();
    void createEvaluation();
    void deleteEvaluation();
    void editEvaluation();
    void deleteTaskSlot();


private:
    Ui::MainWindow *ui;

signals:
    void taskCreateTaskButtonPressed();
    void viewCoursesSignal();
    void viewTASignal();
    void editTaskSignal();
    void viewTasksSignal();
    void saveEvaluationSignal();
    void createEval();
    void editEval();
    void deleteEval();
    void deleteTaskSignal();

};

#endif // MAINWINDOW_H
