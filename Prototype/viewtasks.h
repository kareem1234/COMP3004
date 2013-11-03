#ifndef VIEWTASKS_H
#define VIEWTASKS_H

#include <QDialog>
#include <QLabel>
#include <vector>
#include <stdio.h>

namespace Ui {
class ViewTasks;
}

using namespace std;

class ViewTasks : public QDialog
{
    Q_OBJECT
    
public:
    explicit ViewTasks(QWidget *parent = 0);
    ~ViewTasks();
    void addTasks(vector<string> taskNames);
    void deleteTask();
    
private:
    vector<QLabel*> taskLabels;
    QLabel *label;
    Ui::ViewTasks *ui;

};

#endif // VIEWTASKS_H
