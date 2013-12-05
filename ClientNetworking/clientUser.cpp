
#include "clientUser.h"
#include "Message.cpp"
using namespace std;

clientUser::clientUser(QTcpSocket *c,QObject* parent):
QObject(parent){
    client = c;
}

TA clientUser::TLogin(TA t){
    Message<TA,Task> m(Message<string,int>::getTa,t);
    sendData(m.toString());
    Message<TA,string> rm(read());
    cout<<"finished reading"<<endl;
    TA f(rm.returnA());
    return f;
}

Instructor clientUser:: ILogin(Instructor i){
    Message<Instructor,Task> m(Message<string,int>::getInstructor,i);
    sendData(m.toString());
    Message<Instructor,string> rm(read());
    Instructor f(rm.returnA());
    return f;

}

void clientUser:: emptyBuffer(){
    while( client->bytesAvailable() < 1000){
        client->waitForReadyRead(3000);
    }
    char *buffer = new char[client->bytesAvailable()];
    client->read(buffer,client->bytesAvailable());
}

void clientUser:: sendData(string s){
    cout<<"send message"<<s<<endl;
    client->write(s.c_str());
    cout<<"sent message"<<endl;
}

string clientUser::read(){
    cout<<"attempting to read"<<endl;
    while( client->bytesAvailable() < 1000){
        client->waitForReadyRead(3000);
    }
    char *buffer = new char[client->bytesAvailable()];
    client->read(buffer,client->bytesAvailable());
    string s(buffer);
    cout<<"return data was: "<<s<<endl;
    return s;
}
