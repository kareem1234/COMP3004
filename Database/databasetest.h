#ifndef DATABASETEST_H
#define DATABASETEST_H

#include <QObject>

class DatabaseTest : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseTest(QObject *parent = 0);
    void runTest();
    
signals:
    
public slots:
    
};

#endif // DATABASETEST_H
