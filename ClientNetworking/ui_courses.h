/********************************************************************************
** Form generated from reading UI file 'courses.ui'
**
<<<<<<< HEAD
** Created: Mon Nov 4 11:19:49 2013
=======
** Created: Mon Nov 4 12:11:01 2013
>>>>>>> 2816de39d9883517bca2bdfce0cb35b417347e41
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
        Courses->resize(400, 300);
        label = new QLabel(Courses);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 121, 16));
        label_2 = new QLabel(Courses);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(19, 40, 171, 16));
        label_3 = new QLabel(Courses);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(19, 60, 171, 16));
        label_4 = new QLabel(Courses);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 80, 171, 16));
        label_5 = new QLabel(Courses);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 100, 181, 16));
        label_6 = new QLabel(Courses);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 120, 171, 20));
        label_7 = new QLabel(Courses);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(19, 180, 191, 20));
        passTag = new QLabel(Courses);
        passTag->setObjectName(QString::fromUtf8("passTag"));
        passTag->setGeometry(QRect(230, 180, 60, 16));
        verticalLayoutWidget = new QWidget(Courses);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(199, 39, 181, 101));
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
        label_2->setText(QApplication::translate("Courses", "Expected:COMP1 Recieved:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Courses", "Expected:COMP2 Recieved:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Courses", "Expected:COMP3 Recieved:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Courses", "Expected:COMP4 Recieved:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Courses", "Expected:COMP5 Recieved:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Courses", "Courses successfully recieved:", 0, QApplication::UnicodeUTF8));
        passTag->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Courses: public Ui_Courses {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSES_H
