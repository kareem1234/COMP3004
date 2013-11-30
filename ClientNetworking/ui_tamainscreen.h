/********************************************************************************
** Form generated from reading UI file 'tamainscreen.ui'
**
** Created: Sat Nov 30 17:11:40 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAMAINSCREEN_H
#define UI_TAMAINSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QScrollArea>
#include <QtGui/QScrollBar>
#include <QtGui/QTableWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TAMainScreen
{
public:
    QLabel *lb1;
    QLabel *lb2;
    QLabel *lb3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QScrollBar *verticalScrollBar;
    QTableWidget *taskItems;
    QTextBrowser *details;
    QLabel *lb4;
    QLabel *userName;
    QLabel *courseAssigned;
    QTextBrowser *evaluation;
    QLabel *lb4_2;

    void setupUi(QFrame *TAMainScreen)
    {
        if (TAMainScreen->objectName().isEmpty())
            TAMainScreen->setObjectName(QString::fromUtf8("TAMainScreen"));
        TAMainScreen->resize(574, 423);
        TAMainScreen->setFrameShape(QFrame::StyledPanel);
        TAMainScreen->setFrameShadow(QFrame::Raised);
        lb1 = new QLabel(TAMainScreen);
        lb1->setObjectName(QString::fromUtf8("lb1"));
        lb1->setGeometry(QRect(30, 30, 81, 16));
        lb2 = new QLabel(TAMainScreen);
        lb2->setObjectName(QString::fromUtf8("lb2"));
        lb2->setGeometry(QRect(30, 60, 111, 16));
        lb3 = new QLabel(TAMainScreen);
        lb3->setObjectName(QString::fromUtf8("lb3"));
        lb3->setGeometry(QRect(30, 130, 46, 13));
        scrollArea = new QScrollArea(TAMainScreen);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(30, 160, 261, 221));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 259, 219));
        verticalScrollBar = new QScrollBar(scrollAreaWidgetContents);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(240, 0, 16, 221));
        verticalScrollBar->setOrientation(Qt::Vertical);
        taskItems = new QTableWidget(scrollAreaWidgetContents);
        if (taskItems->columnCount() < 2)
            taskItems->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        taskItems->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        taskItems->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        taskItems->setObjectName(QString::fromUtf8("taskItems"));
        taskItems->setGeometry(QRect(0, 0, 241, 221));
        taskItems->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        taskItems->setAutoScrollMargin(16);
        taskItems->setSelectionBehavior(QAbstractItemView::SelectRows);
        taskItems->setSortingEnabled(true);
        taskItems->horizontalHeader()->setCascadingSectionResizes(true);
        taskItems->horizontalHeader()->setDefaultSectionSize(120);
        taskItems->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        taskItems->verticalHeader()->setVisible(false);
        scrollArea->setWidget(scrollAreaWidgetContents);
        details = new QTextBrowser(TAMainScreen);
        details->setObjectName(QString::fromUtf8("details"));
        details->setGeometry(QRect(320, 70, 231, 131));
        lb4 = new QLabel(TAMainScreen);
        lb4->setObjectName(QString::fromUtf8("lb4"));
        lb4->setGeometry(QRect(320, 50, 46, 13));
        userName = new QLabel(TAMainScreen);
        userName->setObjectName(QString::fromUtf8("userName"));
        userName->setGeometry(QRect(160, 30, 46, 13));
        courseAssigned = new QLabel(TAMainScreen);
        courseAssigned->setObjectName(QString::fromUtf8("courseAssigned"));
        courseAssigned->setGeometry(QRect(160, 60, 46, 13));
        evaluation = new QTextBrowser(TAMainScreen);
        evaluation->setObjectName(QString::fromUtf8("evaluation"));
        evaluation->setGeometry(QRect(320, 250, 231, 131));
        lb4_2 = new QLabel(TAMainScreen);
        lb4_2->setObjectName(QString::fromUtf8("lb4_2"));
        lb4_2->setGeometry(QRect(320, 230, 71, 16));

        retranslateUi(TAMainScreen);

        QMetaObject::connectSlotsByName(TAMainScreen);
    } // setupUi

    void retranslateUi(QFrame *TAMainScreen)
    {
        TAMainScreen->setWindowTitle(QApplication::translate("TAMainScreen", "Frame", 0, QApplication::UnicodeUTF8));
        lb1->setText(QApplication::translate("TAMainScreen", "User Name:", 0, QApplication::UnicodeUTF8));
        lb2->setText(QApplication::translate("TAMainScreen", "Course Assigned:", 0, QApplication::UnicodeUTF8));
        lb3->setText(QApplication::translate("TAMainScreen", "Tasks:", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = taskItems->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("TAMainScreen", "Task", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = taskItems->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("TAMainScreen", "Due Date", 0, QApplication::UnicodeUTF8));
        details->setHtml(QApplication::translate("TAMainScreen", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
        lb4->setText(QApplication::translate("TAMainScreen", "Details:", 0, QApplication::UnicodeUTF8));
        userName->setText(QString());
        courseAssigned->setText(QString());
        evaluation->setHtml(QApplication::translate("TAMainScreen", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
        lb4_2->setText(QApplication::translate("TAMainScreen", "Evaluation:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TAMainScreen: public Ui_TAMainScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAMAINSCREEN_H
