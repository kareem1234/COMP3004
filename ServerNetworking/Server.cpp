// server.cc
#include "Server.h"
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
    QTcpSocket* newClient = server.nextPendingConnection();
    clients.push_back(newClient);

    connect(newClient, SIGNAL(readyRead()),
            this, SLOT(readRequest()));
    connect(newClient,SIGNAL(disconnected()),
            this,SLOT(closeConnection()));

    cout<<"accepted new connection "<<"Total  of " <<clients.size()<<" connection(s)"<<endl;
}

void Server::closeConnection(){
    QTcpSocket* client = (QTcpSocket*)sender();
    for(int i = 0; i<clients.size(); i++){
        if( (clients[i]->socketDescriptor()) == (client->socketDescriptor()) ){
            clients.erase(clients.begin()+i);
            client->close();
        }
    }
    cout<<"client disconnected"<<" Total  of " <<clients.size()<<" connection(s)"<<endl;
	
}

void Server::readRequest(){
    cout<<"new request"<<endl;
    QTcpSocket* client = (QTcpSocket*)sender();
    char* buffer = new char[client->bytesAvailable()];
  	client->read(buffer, client->bytesAvailable());
    cout <<"request was: "<<buffer<< endl;
    string s(buffer);
    MethodInterpreter method(s);
    if(method.isTA()){
        rh = new taRequest(s,client,db);
        rh->respond(client,db);
    }else{
        rh = new instructorRequest(s,client,db);
        rh->respond(client, db);
    }
    delete rh;
    delete buffer;
}



