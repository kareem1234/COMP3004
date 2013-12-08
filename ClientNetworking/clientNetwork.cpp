
#include  "clientNetwork.h"


clientNetwork::clientNetwork(QObject* parent):
    QObject(parent){
        user = 0;
        ta = 0;
        instructor = 0;
        client = new QTcpSocket;
        //client->open(QIODevice::Write);

        this->connect(client,SIGNAL(connected()),this,SLOT(connection()));

        start("127.0.0.1",8888);
}

clientUser* clientNetwork::getUser(){
    user = new clientUser(client);
    return user;
}

clientNetwork::~clientNetwork(){
    deleteUser();
    delete client;
}

taClient* clientNetwork::getTa(){
    ta = new taClient(client);
    return ta;
}

QTcpSocket* clientNetwork:: getClient(){
    return client;
}

void clientNetwork::connection(){
  cout<<"connected to server"<<endl;
}

instructorClient* clientNetwork::getInstructor(){
    instructor = new instructorClient(client);
    return instructor;
}

void clientNetwork::start(QString address, quint16 port){
    cout<<"attempting to connect to server..."<<endl;
    QHostAddress addr(address);
    client->connectToHost(address, port);
}

void clientNetwork::deleteTa(){
    if(ta != 0){
        delete ta;
        ta = 0;
    }
}


void clientNetwork::deleteInstructor(){
    if(instructor != 0){
        delete instructor;
        instructor= 0;
    }
}


void clientNetwork::deleteUser(){
    if(user != 0){
        delete user;
        user= 0;
    }
}
