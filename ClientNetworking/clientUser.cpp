
#include "clientUser.h"
#include "Message.cpp"
using namespace std;

clientUser::clientUser(QTcpSocket *c,QObject* parent):
QObject(parent){
    client = c;
    //emptyBuffer();
}

TA clientUser::TLogin(TA t){
    Message<TA,Task> m(Message<string,int>::getTa,t);
    sendData(m.toString());
    Message<TA,string> rm(Message<string,int>::reTurn,read());
    cout<<"finished reading"<<endl;
    TA f(rm.returnA());
    cout<<"ta is:"<<rm.returnA()<<endl;
    return f;
}

Instructor clientUser:: ILogin(Instructor i){
    Message<Instructor,Task> m(Message<string,int>::getInstructor,i);
    sendData(m.toString());
    cout<<"send data returned"<<endl;
    Message<Instructor,string> rm(Message<string,int>::reTurn,read());
    Instructor f(rm.returnA());
    cout<<"instructor is:"<<rm.returnA()<<endl;
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
    int i =client->write(s.c_str(),1000);
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
