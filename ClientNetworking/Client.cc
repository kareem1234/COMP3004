
// client.cc
#include "Client.h"
using namespace std;

Client::Client(QObject* parent): QObject(parent){
  connect(&client, SIGNAL(connected()),
    this, SLOT(connection()));
}

Client::~Client(){
  client.close();
}

void Client::start(QString address, quint16 port){
  QHostAddress addr(address);
  client.connectToHost(addr, port);
}

void Client::connection(){
  cout<<"connected to server"<<endl;
}

void Client::sendData(string s){
    client.write(s.c_str());
}
