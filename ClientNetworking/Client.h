#ifndef CLIENT_H
#define CLIENT_H

#include <QHostAddress>
#include <QtNetwork>
#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <iostream>

#include <course.h>
#include <ta.h>
#include <instructor.h>
#include <course.h>
#include <task.h>
#include <evaluation.h>
using namespace std;

class Client : public  QObject{
    Q_OBJECT
    public:
          Client(QObject* parent = 0);
          ~Client();
          void start(QString address, quint16 port);
          void saveTask(TA t, Task ts);
          void deleteTask(Task ts);

          void saveEval(TA t, Evaluation e);
          void deleteEval(Evaluation e);
          Evaluation getEval(Task t);


    public slots:
          void connection();



    private:
            QTcpSocket client;
            void sendData(string s);
};




#endif // CLIENT_H
