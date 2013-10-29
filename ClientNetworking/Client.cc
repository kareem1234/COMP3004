
// client.cc
#include "Client.h"
#include "Message.cpp"
using namespace std;

Client::Client(QObject* parent): QObject(parent){
  connect(&client, SIGNAL(connected()),
    this, SLOT(connection()));
}

Client::~Client(){
  client.close();
}

void Client::start(QString address, quint16 port){
  cout<<"attempting to connect to server..."<<endl;
  QHostAddress addr(address);
  client.connectToHost(addr, port);
}

void Client::connection(){
  cout<<"connected to server"<<endl;
}

void Client::sendData(string s){
    cout<<"sending message"<<endl;
    client.write(s.c_str());
}

void Client:: saveTask(TA t, Task ts){
    Message<TA,Task> m(Message<string,int>::saveTask ,t,ts);
    sendData(m.toString());
}

void Client:: saveEval(TA t, Evaluation e){
    Message<TA,Evaluation> m(Message<string,int>::saveEval ,t,e);
    sendData(m.toString());
}

void Client:: deleteEval( Evaluation e){
    Message<Evaluation,TA> m(Message<string,int>::deleteEval,e);
    sendData(m.toString());
}

Evaluation Client::getEval(Task t){
    Message<Task,string> m(Message<string,int>::viewEval,t);
    sendData(m.toString());
    while( client.bytesAvailable() == 0){
        // do nothing
    }
    char *buffer = new char[client.bytesAvailable()];
    client.read(buffer,client.bytesAvailable());
    string s(buffer);
    Message<Evaluation,string> rm(s);
    // eval e(rm.obj1)
    // return e

}

vector<Task> Client::getTaskListForCourse(TA t, Course c){
    Message<TA,Course> m(Message<string,int>::viewTaskListForCourse,t,c);
    sendData(m.toString());
    while( client.bytesAvailable() == 0){
        // do nothing
    }
    char *buffer = new char[client.bytesAvailable()];
    client.read(buffer,client.bytesAvailable());
    string s(buffer);
    Message<Task,string> rm(s);
    // return rm.obj1vec

}

vector<TA> Client:: getTAList(Course c){
    Message<Course,string> m(Message<string,int>::viewTaList,c);
    sendData(m.toString());
    while( client.bytesAvailable() == 0){
        // do nothing
    }
    char *buffer = new char[client.bytesAvailable()];
    client.read(buffer,client.bytesAvailable());
    string s(buffer);
    Message<TA,string> rm(s);
     // return rm.obj1vec

}
vector<Course> Client::getCourseList(Instructor i){
    Message<Instructor,string> m(Message<string,int>::viewCourseList,i);
    sendData(m.toString());
    while( client.bytesAvailable() == 0){
        // do nothing
    }
    char *buffer = new char[client.bytesAvailable()];
    client.read(buffer,client.bytesAvailable());
    string s(buffer);
    Message<TA,string> rm(s);
     // return rm.obj1vec

}



