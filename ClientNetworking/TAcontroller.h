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
    ~TAcontroller();

    TAMainScreen taScreen;
    int row;
    TA self;
private:
    taClient *client;
    Course currentCourse;
    vector<Task> taskList;

signals:
    void logout();

public slots:
    void viewTask();
    void viewTaskDetails(int row);
    void viewEval();
    void clearDetails();
    void cellSelected(int, int);
    void logoutClicked();



};

#endif // TAcontroller_H
