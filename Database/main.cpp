#include <QtCore/QCoreApplication>
#include <iostream>
#include <QTextStream>
#include <QDebug>

#include "databasetest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    DatabaseTest dbTest;
    dbTest.runTest();

    qDebug() << "Helloooo";

    return a.exec();
}
