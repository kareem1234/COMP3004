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
using namespace std;

class Client : public  QObject{
    Q_OBJECT
    public:
          Client(QObject* parent = 0);
          ~Client();
          void start(QString address, quint16 port);
    public slots:
          void connection();
          void sendData(string s);


    private:
            QTcpSocket client;
};




#endif // CLIENT_H
