// server.cc
<<<<<<< HEAD
#include "server.h"
=======
#include "Server.h"
>>>>>>> 3d37eefe61c6cf09142a31c9945bd26eb3b1e4bc
using namespace std;

Server::Server(QObject* parent): QObject(parent){
	connect(&server, SIGNAL(newConnection()),
    		this, SLOT(acceptConnection()));

	server.listen(QHostAddress::Any, 8888);
<<<<<<< HEAD
	cout<<"listening on port 8888"<<endl;
=======
    cout<<"listening on port 8888"<<endl;
>>>>>>> 3d37eefe61c6cf09142a31c9945bd26eb3b1e4bc
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



