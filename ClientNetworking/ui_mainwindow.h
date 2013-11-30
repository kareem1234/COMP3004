/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Nov 30 16:47:04 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *createTask;
    QPushButton *viewCourses;
    QPushButton *taskEdited;
    QPushButton *evaluation;
    QPushButton *taskView;
    QPushButton *viewTA;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 316);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        createTask = new QPushButton(centralWidget);
        createTask->setObjectName(QString::fromUtf8("createTask"));
        createTask->setGeometry(QRect(109, 10, 151, 31));
        viewCourses = new QPushButton(centralWidget);
        viewCourses->setObjectName(QString::fromUtf8("viewCourses"));
        viewCourses->setGeometry(QRect(110, 50, 151, 31));
        taskEdited = new QPushButton(centralWidget);
        taskEdited->setObjectName(QString::fromUtf8("taskEdited"));
        taskEdited->setGeometry(QRect(110, 90, 151, 31));
        evaluation = new QPushButton(centralWidget);
        evaluation->setObjectName(QString::fromUtf8("evaluation"));
        evaluation->setGeometry(QRect(110, 136, 151, 31));
        taskView = new QPushButton(centralWidget);
        taskView->setObjectName(QString::fromUtf8("taskView"));
        taskView->setGeometry(QRect(109, 176, 151, 31));
        viewTA = new QPushButton(centralWidget);
        viewTA->setObjectName(QString::fromUtf8("viewTA"));
        viewTA->setGeometry(QRect(109, 216, 151, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 24));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        createTask->setText(QApplication::translate("MainWindow", "Create Task", 0, QApplication::UnicodeUTF8));
        viewCourses->setText(QApplication::translate("MainWindow", "View Courses", 0, QApplication::UnicodeUTF8));
        taskEdited->setText(QApplication::translate("MainWindow", "Edit Task", 0, QApplication::UnicodeUTF8));
        evaluation->setText(QApplication::translate("MainWindow", "Evaluation", 0, QApplication::UnicodeUTF8));
        taskView->setText(QApplication::translate("MainWindow", "View All Tasks", 0, QApplication::UnicodeUTF8));
        viewTA->setText(QApplication::translate("MainWindow", "View All TA's", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
