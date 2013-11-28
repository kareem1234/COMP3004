/********************************************************************************
** Form generated from reading UI file 'edittask.ui'
**
** Created: Thu Nov 28 17:54:27 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITTASK_H
#define UI_EDITTASK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_EditTask
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *descAfter;
    QLabel *dateBefore;
    QLabel *descBefore;
    QLabel *dateAfter;
    QLabel *label_14;
    QLabel *typeBefore;
    QLabel *typeAfter;
    QLabel *label_9;
    QLabel *taskEdited;

    void setupUi(QDialog *EditTask)
    {
        if (EditTask->objectName().isEmpty())
            EditTask->setObjectName(QString::fromUtf8("EditTask"));
        EditTask->resize(400, 300);
        label = new QLabel(EditTask);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 121, 16));
        label_2 = new QLabel(EditTask);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 60, 60, 16));
        label_3 = new QLabel(EditTask);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 90, 71, 16));
        label_4 = new QLabel(EditTask);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 120, 71, 16));
        label_5 = new QLabel(EditTask);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(200, 30, 111, 16));
        label_6 = new QLabel(EditTask);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(200, 60, 60, 16));
        label_7 = new QLabel(EditTask);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(200, 90, 71, 16));
        label_8 = new QLabel(EditTask);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(200, 120, 71, 16));
        descAfter = new QLabel(EditTask);
        descAfter->setObjectName(QString::fromUtf8("descAfter"));
        descAfter->setGeometry(QRect(200, 150, 191, 20));
        dateBefore = new QLabel(EditTask);
        dateBefore->setObjectName(QString::fromUtf8("dateBefore"));
        dateBefore->setGeometry(QRect(100, 90, 101, 16));
        descBefore = new QLabel(EditTask);
        descBefore->setObjectName(QString::fromUtf8("descBefore"));
        descBefore->setGeometry(QRect(10, 150, 181, 16));
        dateAfter = new QLabel(EditTask);
        dateAfter->setObjectName(QString::fromUtf8("dateAfter"));
        dateAfter->setGeometry(QRect(280, 90, 111, 16));
        label_14 = new QLabel(EditTask);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(310, 60, 60, 16));
        typeBefore = new QLabel(EditTask);
        typeBefore->setObjectName(QString::fromUtf8("typeBefore"));
        typeBefore->setGeometry(QRect(100, 60, 101, 16));
        typeAfter = new QLabel(EditTask);
        typeAfter->setObjectName(QString::fromUtf8("typeAfter"));
        typeAfter->setGeometry(QRect(249, 60, 101, 16));
        label_9 = new QLabel(EditTask);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(110, 180, 91, 16));
        taskEdited = new QLabel(EditTask);
        taskEdited->setObjectName(QString::fromUtf8("taskEdited"));
        taskEdited->setGeometry(QRect(230, 180, 60, 16));

        retranslateUi(EditTask);

        QMetaObject::connectSlotsByName(EditTask);
    } // setupUi

    void retranslateUi(QDialog *EditTask)
    {
        EditTask->setWindowTitle(QApplication::translate("EditTask", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("EditTask", "Before Editing:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("EditTask", "Type:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("EditTask", "Due Date:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("EditTask", "Desription:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("EditTask", "After Editing:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("EditTask", "Type:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("EditTask", "Due Date:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("EditTask", "Desription:", 0, QApplication::UnicodeUTF8));
        descAfter->setText(QString());
        dateBefore->setText(QString());
        descBefore->setText(QString());
        dateAfter->setText(QString());
        label_14->setText(QString());
        typeBefore->setText(QString());
        typeAfter->setText(QString());
        label_9->setText(QApplication::translate("EditTask", "Task Edited:", 0, QApplication::UnicodeUTF8));
        taskEdited->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EditTask: public Ui_EditTask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITTASK_H
