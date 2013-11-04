#ifndef SERVER_H
#define SERVER_H
#include <QtNetwork>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>
#include <vector>
#include "requesthandler.h"
#include "databasecontroller.h"


using namespace std;


class Server: public QObject {
	Q_OBJECT
	public:
  		Server(QObject * parent = 0);
  		~Server();
	public slots:
  		 void acceptConnection();
         void readRequest();
         void closeConnection();

	private:
  		QTcpServer server;
  		QTcpSocket* client;
        vector<QTcpSocket*> clients;
        RequestHandler *rh;
        DatabaseController db;

};
#endif
