#ifndef CLIENTNETWORK_H
#define CLIENTNETWORK_H
#include <QHostAddress>
#include <QtNetwork>
#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <iostream>
#include <vector>


using namespace std;

class clientNetwork : public  QObject{
    Q_OBJECT
    public:
          clientNetwork(QObject* parent = 0);
          ~clientNetwork();
          void start(QString address, quint16 port);

    public slots:
          void connection();



    private:
            QTcpSocket client;

};


#endif // CLIENTNETWORK_H
