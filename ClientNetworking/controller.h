#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <mainwindow.h>
#include <Client.h>
#include <course.h>
#include <ta.h>
#include <instructor.h>
#include <course.h>
#include <task.h>
#include <evaluation.h>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);
    MainWindow view;
    Client connection;
    int count;
    
signals:
    
public slots:
    void createTask();
    void viewCourses();
    void viewTA();
    void viewTask();
    void editTask();
    void saveEvaluation();
    void createEvaluation();
    void deleteEvaluation();
    void editEvaluation();
    void deleteTask();
    string toString(int a);

};

#endif // CONTROLLER_H
