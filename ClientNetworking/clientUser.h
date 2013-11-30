#ifndef CLIENTUSER_H
#define CLIENTUSER_H

#include <QHostAddress>
#include <QtNetwork>
#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <iostream>
#include <vector>
\
#include <course.h>
#include <ta.h>
#include <instructor.h>
#include <course.h>
#include <task.h>
#include <evaluation.h>

using namespace std;

class clientUser : public  QObject{
    Q_OBJECT
    public:
          clientUser( QTcpSocket *c,QObject* parent = 0);


    public slots:




    protected:
            QTcpSocket *client;
            Instructor ILogin(Instructor t);
            TA TLogin(TA t);
            void sendData(string s);
            void emptyBuffer();
            string read();

};

#endif // CLIENTUSER_H
