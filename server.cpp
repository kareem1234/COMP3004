// server.cc
#include "server.h"
using namespace std;

Server::Server(QObject* parent): QObject(parent){
	connect(&server, SIGNAL(newConnection()),
    		this, SLOT(acceptConnection()));

	server.listen(QHostAddress::Any, 8888);
	cout<<"listening on port 8888"<<endl;
}

Server::~Server(){
  server.close();
}

void Server::acceptConnection(){
  client = server.nextPendingConnection();

	connect(client, SIGNAL(readyRead()),
    		this, SLOT(startRead()));
}

void Server::startRead(){
	char buffer[1024] = {0};
  	client->read(buffer, client->bytesAvailable());
  	cout << buffer<< endl;
  	client->close();
}



