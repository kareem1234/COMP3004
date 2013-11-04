/********************************************************************************
** Form generated from reading UI file 'taskcreated.ui'
**
** Created: Mon Nov 4 12:11:01 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKCREATED_H
#define UI_TASKCREATED_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_TaskCreated
{
public:
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QLabel *taskType;
    QLabel *taskDescription;
    QLabel *dueDate;

    void setupUi(QDialog *TaskCreated)
    {
        if (TaskCreated->objectName().isEmpty())
            TaskCreated->setObjectName(QString::fromUtf8("TaskCreated"));
        TaskCreated->resize(247, 206);
        label_2 = new QLabel(TaskCreated);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 40, 71, 31));
        label_3 = new QLabel(TaskCreated);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(21, 70, 91, 20));
        label = new QLabel(TaskCreated);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 71, 20));
        taskType = new QLabel(TaskCreated);
        taskType->setObjectName(QString::fromUtf8("taskType"));
        taskType->setGeometry(QRect(70, 40, 71, 31));
        taskDescription = new QLabel(TaskCreated);
        taskDescription->setObjectName(QString::fromUtf8("taskDescription"));
        taskDescription->setGeometry(QRect(110, 70, 121, 121));
        dueDate = new QLabel(TaskCreated);
        dueDate->setObjectName(QString::fromUtf8("dueDate"));
        dueDate->setGeometry(QRect(90, 20, 60, 21));

        retranslateUi(TaskCreated);

        QMetaObject::connectSlotsByName(TaskCreated);
    } // setupUi

    void retranslateUi(QDialog *TaskCreated)
    {
        TaskCreated->setWindowTitle(QApplication::translate("TaskCreated", "Dialog", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TaskCreated", "Type:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TaskCreated", "Description:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TaskCreated", "Due Date:", 0, QApplication::UnicodeUTF8));
        taskType->setText(QString());
        taskDescription->setText(QString());
        dueDate->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TaskCreated: public Ui_TaskCreated {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKCREATED_H
