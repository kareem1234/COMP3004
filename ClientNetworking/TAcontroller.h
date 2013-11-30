#ifndef TAcontroller_H
#define TAcontroller_H

#include <QObject>
#include <Client.h>
#include <ta.h>
#include <course.h>
#include <task.h>
#include <evaluation.h>
#include <tamainscreen.h>

class TAcontroller : public QObject
{
    Q_OBJECT
public:
    explicit TAcontroller(QObject *parent = 0);
    TAMainScreen taScreen;
    Client connection;
    string toString(int a);
    int row;
signals:
    
public slots:
    void viewTask();
    void viewEval();
    void cellSelected(int, int);



};

#endif // TAcontroller_H
