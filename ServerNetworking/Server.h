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
#include  "methodInterpreter.h"
#include "request.h"
#include "instructorRequest.h"
#include "taRequest.h"


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
        Request *rh;
        DatabaseController db;

};
#endif
