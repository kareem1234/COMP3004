#ifndef CLIENTNETWORK_H
#define CLIENTNETWORK_H
#include <QHostAddress>
#include <QtNetwork>
#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <iostream>
#include "instructorClient.h"
#include "taClient.h"
#include "clientUser.h"

using namespace std;

class clientNetwork : public  QObject{
    Q_OBJECT
    public:
          clientNetwork(QObject* parent = 0);
          ~clientNetwork();
          void start(QString address, quint16 port);
          taClient* getTa();
          instructorClient* getInstructor();
          void deleteUser();
          QTcpSocket* getClient();
          clientUser* getUser();

    public slots:
          void connection();



    private:
            QTcpSocket * client;
            clientUser* user;
            taClient* ta;
            instructorClient* instructor;

};


#endif // CLIENTNETWORK_H
