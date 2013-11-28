#ifndef CLIENTUSER_H
#define CLIENTUSER_H

#include <QHostAddress>
#include <QtNetwork>
#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <iostream>
#include <vector>

using namespace std;

class clientUser : public  QObject{
    Q_OBJECT
    public:
          clientUser( QTcpSocket c,QObject* parent = 0);
          ~clientUser();


    public slots:




    protected:
            QTcpSocket client;
            virtual void senData(string s);
            virtual void emptyBuffer();
            virtual string read();

};

#endif // CLIENTUSER_H
