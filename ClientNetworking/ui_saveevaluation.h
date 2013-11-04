/********************************************************************************
** Form generated from reading UI file 'saveevaluation.ui'
**
** Created: Mon Nov 4 12:11:01 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEEVALUATION_H
#define UI_SAVEEVALUATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SaveEvaluation
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *createEvaluation;
    QLabel *label_4;
    QPushButton *editEvaluation;
    QPushButton *deleteEvaluation;
    QLabel *taskGrade;
    QLabel *taskFeedback;
    QLabel *evalStatus;

    void setupUi(QDialog *SaveEvaluation)
    {
        if (SaveEvaluation->objectName().isEmpty())
            SaveEvaluation->setObjectName(QString::fromUtf8("SaveEvaluation"));
        SaveEvaluation->resize(380, 201);
        SaveEvaluation->setModal(true);
        label = new QLabel(SaveEvaluation);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(39, 30, 81, 20));
        label_2 = new QLabel(SaveEvaluation);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(39, 60, 101, 20));
        label_3 = new QLabel(SaveEvaluation);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 90, 151, 20));
        createEvaluation = new QPushButton(SaveEvaluation);
        createEvaluation->setObjectName(QString::fromUtf8("createEvaluation"));
        createEvaluation->setGeometry(QRect(10, 160, 121, 27));
        label_4 = new QLabel(SaveEvaluation);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 0, 191, 21));
        editEvaluation = new QPushButton(SaveEvaluation);
        editEvaluation->setObjectName(QString::fromUtf8("editEvaluation"));
        editEvaluation->setGeometry(QRect(140, 160, 111, 27));
        deleteEvaluation = new QPushButton(SaveEvaluation);
        deleteEvaluation->setObjectName(QString::fromUtf8("deleteEvaluation"));
        deleteEvaluation->setGeometry(QRect(259, 160, 111, 27));
        taskGrade = new QLabel(SaveEvaluation);
        taskGrade->setObjectName(QString::fromUtf8("taskGrade"));
        taskGrade->setGeometry(QRect(120, 30, 60, 21));
        taskFeedback = new QLabel(SaveEvaluation);
        taskFeedback->setObjectName(QString::fromUtf8("taskFeedback"));
        taskFeedback->setGeometry(QRect(140, 60, 91, 21));
        evalStatus = new QLabel(SaveEvaluation);
        evalStatus->setObjectName(QString::fromUtf8("evalStatus"));
        evalStatus->setGeometry(QRect(160, 90, 101, 21));

        retranslateUi(SaveEvaluation);

        QMetaObject::connectSlotsByName(SaveEvaluation);
    } // setupUi

    void retranslateUi(QDialog *SaveEvaluation)
    {
        SaveEvaluation->setWindowTitle(QApplication::translate("SaveEvaluation", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SaveEvaluation", "Task Grade:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SaveEvaluation", "Task Feedback:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SaveEvaluation", "Evaluation Status:", 0, QApplication::UnicodeUTF8));
        createEvaluation->setText(QApplication::translate("SaveEvaluation", "Create Evaluation", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SaveEvaluation", "Evaluation for task #1", 0, QApplication::UnicodeUTF8));
        editEvaluation->setText(QApplication::translate("SaveEvaluation", "Edit Evaluation", 0, QApplication::UnicodeUTF8));
        deleteEvaluation->setText(QApplication::translate("SaveEvaluation", "DeleteEvaluation", 0, QApplication::UnicodeUTF8));
        taskGrade->setText(QString());
        taskFeedback->setText(QString());
        evalStatus->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SaveEvaluation: public Ui_SaveEvaluation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEEVALUATION_H
