#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <mainwindow.h>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);
    MainWindow view;
    
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

};

#endif // CONTROLLER_H
