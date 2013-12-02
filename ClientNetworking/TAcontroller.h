#ifndef TAcontroller_H
#define TAcontroller_H

#include <QObject>
#include <ta.h>
#include <course.h>
#include <task.h>
#include <evaluation.h>
#include <tamainscreen.h>
#include "taClient.h"

class TAcontroller : public QObject
{
    Q_OBJECT
public:
    TAcontroller(taClient* c ,TA t,QObject *parent = 0);
    TAMainScreen taScreen;
    int row;
    TA self;
private:
    taClient *client;
signals:
    
public slots:
    void viewTask();
    void viewEval();
    void cellSelected(int, int);



};

#endif // TAcontroller_H
