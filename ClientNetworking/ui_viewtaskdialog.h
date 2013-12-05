/********************************************************************************
** Form generated from reading UI file 'viewtaskdialog.ui'
**
** Created: Tue Dec 3 13:21:36 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWTASKDIALOG_H
#define UI_VIEWTASKDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ViewTaskDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *description;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *monthComboBox;
    QComboBox *dayComboBox;
    QComboBox *timeComboBox1;
    QComboBox *timeComboBox2;
    QPushButton *pushButton;
    QLineEdit *taskNameLabel;

    void setupUi(QDialog *ViewTaskDialog)
    {
        if (ViewTaskDialog->objectName().isEmpty())
            ViewTaskDialog->setObjectName(QString::fromUtf8("ViewTaskDialog"));
        ViewTaskDialog->resize(400, 300);
        label = new QLabel(ViewTaskDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 81, 16));
        label_2 = new QLabel(ViewTaskDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 40, 71, 16));
        label_3 = new QLabel(ViewTaskDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 80, 60, 16));
        description = new QTextEdit(ViewTaskDialog);
        description->setObjectName(QString::fromUtf8("description"));
        description->setGeometry(QRect(20, 110, 241, 101));
        label_4 = new QLabel(ViewTaskDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 40, 51, 16));
        label_5 = new QLabel(ViewTaskDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(180, 40, 31, 16));
        label_6 = new QLabel(ViewTaskDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(250, 40, 41, 16));
        monthComboBox = new QComboBox(ViewTaskDialog);
        monthComboBox->setObjectName(QString::fromUtf8("monthComboBox"));
        monthComboBox->setGeometry(QRect(140, 40, 41, 26));
        dayComboBox = new QComboBox(ViewTaskDialog);
        dayComboBox->setObjectName(QString::fromUtf8("dayComboBox"));
        dayComboBox->setGeometry(QRect(210, 40, 41, 26));
        timeComboBox1 = new QComboBox(ViewTaskDialog);
        timeComboBox1->setObjectName(QString::fromUtf8("timeComboBox1"));
        timeComboBox1->setGeometry(QRect(290, 40, 51, 26));
        timeComboBox2 = new QComboBox(ViewTaskDialog);
        timeComboBox2->setObjectName(QString::fromUtf8("timeComboBox2"));
        timeComboBox2->setGeometry(QRect(340, 40, 51, 26));
        pushButton = new QPushButton(ViewTaskDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 250, 90, 27));
        taskNameLabel = new QLineEdit(ViewTaskDialog);
        taskNameLabel->setObjectName(QString::fromUtf8("taskNameLabel"));
        taskNameLabel->setGeometry(QRect(110, 10, 171, 26));

        retranslateUi(ViewTaskDialog);

        QMetaObject::connectSlotsByName(ViewTaskDialog);
    } // setupUi

    void retranslateUi(QDialog *ViewTaskDialog)
    {
        ViewTaskDialog->setWindowTitle(QApplication::translate("ViewTaskDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ViewTaskDialog", "Task Name:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ViewTaskDialog", "Due Date:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ViewTaskDialog", "Details:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ViewTaskDialog", "Month:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ViewTaskDialog", "Day:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ViewTaskDialog", "Time:", 0, QApplication::UnicodeUTF8));
        monthComboBox->clear();
        monthComboBox->insertItems(0, QStringList()
         << QApplication::translate("ViewTaskDialog", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ViewTaskDialog", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ViewTaskDialog", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ViewTaskDialog", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ViewTaskDialog", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ViewTaskDialog", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ViewTaskDialog", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ViewTaskDialog", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ViewTaskDialog", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ViewTaskDialog", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ViewTaskDialog", "11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ViewTaskDialog", "12", 0, QApplication::UnicodeUTF8)
        );
        timeComboBox2->clear();
        timeComboBox2->insertItems(0, QStringList()
         << QApplication::translate("ViewTaskDialog", "00", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ViewTaskDialog", "30", 0, QApplication::UnicodeUTF8)
        );
        pushButton->setText(QApplication::translate("ViewTaskDialog", "Save Changes", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViewTaskDialog: public Ui_ViewTaskDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWTASKDIALOG_H
