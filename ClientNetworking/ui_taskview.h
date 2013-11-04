/********************************************************************************
** Form generated from reading UI file 'taskview.ui'
**
<<<<<<< HEAD
** Created: Mon Nov 4 11:19:50 2013
=======
** Created: Mon Nov 4 12:11:01 2013
>>>>>>> 2816de39d9883517bca2bdfce0cb35b417347e41
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKVIEW_H
#define UI_TASKVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskView
{
public:
    QPushButton *deleteTaskButton;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *TaskView)
    {
        if (TaskView->objectName().isEmpty())
            TaskView->setObjectName(QString::fromUtf8("TaskView"));
        TaskView->resize(400, 300);
        deleteTaskButton = new QPushButton(TaskView);
        deleteTaskButton->setObjectName(QString::fromUtf8("deleteTaskButton"));
        deleteTaskButton->setGeometry(QRect(150, 250, 90, 27));
        label = new QLabel(TaskView);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 141, 16));
        verticalLayoutWidget = new QWidget(TaskView);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(110, 40, 160, 201));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(TaskView);

        QMetaObject::connectSlotsByName(TaskView);
    } // setupUi

    void retranslateUi(QDialog *TaskView)
    {
        TaskView->setWindowTitle(QApplication::translate("TaskView", "Dialog", 0, QApplication::UnicodeUTF8));
        deleteTaskButton->setText(QApplication::translate("TaskView", "Delete Task", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TaskView", "Tasks For COMP1:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TaskView: public Ui_TaskView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKVIEW_H
