/********************************************************************************
** Form generated from reading UI file 'courses.ui'
**
** Created: Sat Nov 30 16:47:04 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURSES_H
#define UI_COURSES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Courses
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *passTag;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *Courses)
    {
        if (Courses->objectName().isEmpty())
            Courses->setObjectName(QString::fromUtf8("Courses"));
        Courses->resize(539, 300);
        label = new QLabel(Courses);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 121, 16));
        label_2 = new QLabel(Courses);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(19, 40, 281, 16));
        label_3 = new QLabel(Courses);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(19, 60, 281, 16));
        label_4 = new QLabel(Courses);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 80, 291, 16));
        label_5 = new QLabel(Courses);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 100, 271, 16));
        label_6 = new QLabel(Courses);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 120, 281, 20));
        label_7 = new QLabel(Courses);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(19, 180, 191, 20));
        passTag = new QLabel(Courses);
        passTag->setObjectName(QString::fromUtf8("passTag"));
        passTag->setGeometry(QRect(230, 180, 60, 16));
        verticalLayoutWidget = new QWidget(Courses);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(310, 40, 181, 131));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(Courses);

        QMetaObject::connectSlotsByName(Courses);
    } // setupUi

    void retranslateUi(QDialog *Courses)
    {
        Courses->setWindowTitle(QApplication::translate("Courses", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Courses", "Courses Assigned:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Courses", "Expected: Software Engeneering   Recieved:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Courses", "Expected:Programming Paradigms Recieved:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Courses", "Expected: Intro to Computer Science Recieved:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Courses", "Expected:Systems Programming Recieved:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Courses", "Expected:Descrete Mathematics Recieved:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Courses", "Courses successfully recieved:", 0, QApplication::UnicodeUTF8));
        passTag->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Courses: public Ui_Courses {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSES_H
