
// client.cc
#include "Client.h"
using namespace std;

Client::Client(QObject* parent): QObject(parent){
  connect(&client, SIGNAL(connected()),
    this, SLOT(startTransfer()));
}

Client::~Client(){
  client.close();
}

void Client::start(QString address, quint16 port){
  QHostAddress addr(address);
  client.connectToHost(addr, port);
}

void Client::startTransfer(){
  cout<<"writing hello world"<<endl;
  client.write("Hello, world", 13);
}
