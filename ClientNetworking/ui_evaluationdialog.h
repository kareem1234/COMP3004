/********************************************************************************
** Form generated from reading UI file 'evaluationdialog.ui'
**
** Created: Mon Dec 9 16:24:00 2013
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
    QComboBox *gradeCombo;
    QTextEdit *comments;
    QLabel *label_3;
    QLabel *hasEvalTag;
    QPushButton *createEval;
    QPushButton *deleteButton;
    QPushButton *saveChangesButton;

    void setupUi(QDialog *EvaluationDialog)
    {
        if (EvaluationDialog->objectName().isEmpty())
            EvaluationDialog->setObjectName(QString::fromUtf8("EvaluationDialog"));
        EvaluationDialog->resize(431, 300);
        EvaluationDialog->setModal(false);
        label = new QLabel(EvaluationDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 61, 31));
        label_2 = new QLabel(EvaluationDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 60, 81, 16));
        gradeCombo = new QComboBox(EvaluationDialog);
        gradeCombo->setObjectName(QString::fromUtf8("gradeCombo"));
        gradeCombo->setGeometry(QRect(100, 20, 111, 31));
        comments = new QTextEdit(EvaluationDialog);
        comments->setObjectName(QString::fromUtf8("comments"));
        comments->setGeometry(QRect(100, 60, 261, 161));
        label_3 = new QLabel(EvaluationDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 230, 121, 16));
        hasEvalTag = new QLabel(EvaluationDialog);
        hasEvalTag->setObjectName(QString::fromUtf8("hasEvalTag"));
        hasEvalTag->setGeometry(QRect(230, 230, 60, 16));
        createEval = new QPushButton(EvaluationDialog);
        createEval->setObjectName(QString::fromUtf8("createEval"));
        createEval->setGeometry(QRect(20, 260, 121, 27));
        deleteButton = new QPushButton(EvaluationDialog);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setEnabled(false);
        deleteButton->setGeometry(QRect(280, 260, 121, 27));
        saveChangesButton = new QPushButton(EvaluationDialog);
        saveChangesButton->setObjectName(QString::fromUtf8("saveChangesButton"));
        saveChangesButton->setEnabled(false);
        saveChangesButton->setGeometry(QRect(160, 260, 111, 27));

        retranslateUi(EvaluationDialog);

        QMetaObject::connectSlotsByName(EvaluationDialog);
    } // setupUi

    void retranslateUi(QDialog *EvaluationDialog)
    {
        EvaluationDialog->setWindowTitle(QApplication::translate("EvaluationDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("EvaluationDialog", "Grade:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("EvaluationDialog", "Comments:", 0, QApplication::UnicodeUTF8));
        gradeCombo->clear();
        gradeCombo->insertItems(0, QStringList()
         << QApplication::translate("EvaluationDialog", "1(Poor)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EvaluationDialog", "2(Passable)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EvaluationDialog", "3(Good)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EvaluationDialog", "4(Very Good)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EvaluationDialog", "5(Excellent)", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("EvaluationDialog", "Task Has Evaluation:", 0, QApplication::UnicodeUTF8));
        hasEvalTag->setText(QApplication::translate("EvaluationDialog", "False", 0, QApplication::UnicodeUTF8));
        createEval->setText(QApplication::translate("EvaluationDialog", "Create Evaluation", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("EvaluationDialog", "Delete Evaluation", 0, QApplication::UnicodeUTF8));
        saveChangesButton->setText(QApplication::translate("EvaluationDialog", "Save Changes", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EvaluationDialog: public Ui_EvaluationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVALUATIONDIALOG_H
