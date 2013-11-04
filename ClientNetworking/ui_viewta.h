/********************************************************************************
** Form generated from reading UI file 'viewta.ui'
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

#ifndef UI_VIEWTA_H
#define UI_VIEWTA_H

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

class Ui_ViewTA
{
public:
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *ViewTA)
    {
        if (ViewTA->objectName().isEmpty())
            ViewTA->setObjectName(QString::fromUtf8("ViewTA"));
        ViewTA->resize(400, 300);
        label = new QLabel(ViewTA);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 131, 16));
        verticalLayoutWidget = new QWidget(ViewTA);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(79, 50, 251, 231));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(ViewTA);

        QMetaObject::connectSlotsByName(ViewTA);
    } // setupUi

    void retranslateUi(QDialog *ViewTA)
    {
        ViewTA->setWindowTitle(QApplication::translate("ViewTA", "TA List", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ViewTA", "TA's for COMP1:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViewTA: public Ui_ViewTA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWTA_H
