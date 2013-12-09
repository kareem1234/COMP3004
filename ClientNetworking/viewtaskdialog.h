#ifndef VIEWTASKDIALOG_H
#define VIEWTASKDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "task.h"
#include <QPushButton>

namespace Ui {
class ViewTaskDialog;
}

class ViewTaskDialog : public QDialog
{
    Q_OBJECT
    
public:
    QPushButton *createTask;
    explicit ViewTaskDialog(QWidget *parent = 0);
    void setTaskDate(int taskMonth,int taskDay,int taskTimeHours,int taskTimeMinutes);//This function sets the date for the task selected
    void setTaskDescription(QString description);//This function sets the description for the task
    void setTaskNameTag(QString description);//This function sets the task name tag
    void getTaskAtributes(Task* t);//this method assigns all of the atributes in the task dialogue to a task(ADD TASK POINTER AND SET VALUES TO CORRESPONDING DUMMY VARIABLES)

    ~ViewTaskDialog();
    
private:
    Ui::ViewTaskDialog *ui;

signals:

    void saveChanges();

public slots:
    void setAmountOfDays();
    void confirmSave();
};

#endif // VIEWTASKDIALOG_H
