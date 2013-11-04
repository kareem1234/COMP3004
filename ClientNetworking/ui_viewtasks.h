/********************************************************************************
** Form generated from reading UI file 'viewtasks.ui'
**
** Created: Mon Nov 4 11:53:28 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWTASKS_H
#define UI_VIEWTASKS_H

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

class Ui_ViewTasks
{
public:
    QLabel *label;
    QPushButton *deleteButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *ViewTasks)
    {
        if (ViewTasks->objectName().isEmpty())
            ViewTasks->setObjectName(QString::fromUtf8("ViewTasks"));
        ViewTasks->resize(400, 300);
        label = new QLabel(ViewTasks);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 111, 16));
        deleteButton = new QPushButton(ViewTasks);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(129, 260, 121, 27));
        verticalLayoutWidget = new QWidget(ViewTasks);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(110, 39, 160, 211));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(ViewTasks);

        QMetaObject::connectSlotsByName(ViewTasks);
    } // setupUi

    void retranslateUi(QDialog *ViewTasks)
    {
        ViewTasks->setWindowTitle(QApplication::translate("ViewTasks", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ViewTasks", "Tasks for COMP1:", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("ViewTasks", "Delete Task", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViewTasks: public Ui_ViewTasks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWTASKS_H
