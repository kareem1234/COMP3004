/********************************************************************************
** Form generated from reading UI file 'evaluationdialog.ui'
**
** Created: Tue Dec 3 13:21:36 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVALUATIONDIALOG_H
#define UI_EVALUATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_EvaluationDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QComboBox *grade;
    QTextEdit *remarks;
    QPushButton *deleteButton;
    QPushButton *saveButton;

    void setupUi(QDialog *EvaluationDialog)
    {
        if (EvaluationDialog->objectName().isEmpty())
            EvaluationDialog->setObjectName(QString::fromUtf8("EvaluationDialog"));
        EvaluationDialog->resize(400, 300);
        label = new QLabel(EvaluationDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 111, 21));
        label_2 = new QLabel(EvaluationDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 80, 131, 16));
        grade = new QComboBox(EvaluationDialog);
        grade->setObjectName(QString::fromUtf8("grade"));
        grade->setEnabled(false);
        grade->setGeometry(QRect(140, 30, 78, 26));
        remarks = new QTextEdit(EvaluationDialog);
        remarks->setObjectName(QString::fromUtf8("remarks"));
        remarks->setEnabled(false);
        remarks->setGeometry(QRect(160, 80, 231, 161));
        deleteButton = new QPushButton(EvaluationDialog);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setEnabled(false);
        deleteButton->setGeometry(QRect(30, 260, 141, 27));
        saveButton = new QPushButton(EvaluationDialog);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setEnabled(false);
        saveButton->setGeometry(QRect(180, 260, 131, 27));

        retranslateUi(EvaluationDialog);

        QMetaObject::connectSlotsByName(EvaluationDialog);
    } // setupUi

    void retranslateUi(QDialog *EvaluationDialog)
    {
        EvaluationDialog->setWindowTitle(QApplication::translate("EvaluationDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("EvaluationDialog", "Evluation Grade :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("EvaluationDialog", "Evaluation Remarks:", 0, QApplication::UnicodeUTF8));
        grade->clear();
        grade->insertItems(0, QStringList()
         << QApplication::translate("EvaluationDialog", "1(Poor)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EvaluationDialog", "2(Fair)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EvaluationDialog", "3(Good)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EvaluationDialog", "4(Very Good)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EvaluationDialog", "5(Excelent)", 0, QApplication::UnicodeUTF8)
        );
        deleteButton->setText(QApplication::translate("EvaluationDialog", "Delete Evaluation", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("EvaluationDialog", "Save Changes", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EvaluationDialog: public Ui_EvaluationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVALUATIONDIALOG_H
