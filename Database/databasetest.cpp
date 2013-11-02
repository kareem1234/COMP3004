#include "databasetest.h"
#include "databasecontroller.h"
#include <QDebug>

DatabaseTest::DatabaseTest(QObject *parent) :
    QObject(parent)
{  
}

void DatabaseTest::runTest()
{
    DatabaseController dbController;



    qDebug() << "Running test";
}



