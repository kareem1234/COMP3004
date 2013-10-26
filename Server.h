#include <QtNetwork>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>



class Server: public QObject {
	Q_OBJECT
	public:
  		Server(QObject * parent = 0);
  		~Server();
	public slots:
  		 void acceptConnection();
 		 void startRead();
	private:
  		QTcpServer server;
  		QTcpSocket* client;
};
