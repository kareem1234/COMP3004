#ifndef TASKVIEW_H
#define TASKVIEW_H

#include <QDialog>
#include <QLabel>
#include <vector>
#include <stdio.h>

using namespace std;

namespace Ui {
class TaskView;
}

class TaskView : public QDialog
{
    Q_OBJECT
    
public:
    explicit TaskView(QWidget *parent = 0);
    ~TaskView();
    void addTasks(vector<string> taskNames);
    void deleteTask();

private:
    vector<QLabel*> taskLabels;
    QLabel *label;
    Ui::TaskView *ui;
signals:
    void deletePressed();
private slots:
    void deleteButtonSlot();


};

#endif // TASKVIEW_H
