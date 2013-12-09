#ifndef REQUEST_H
#define REQUEST_H

#include "Message.cpp"
#include <iostream>
#include <string>
#include <QtNetwork>
#include <QObject>
#include <QTcpSocket>
#include <course.h>
#include <ta.h>
#include <instructor.h>
#include <course.h>
#include <task.h>
#include <evaluation.h>
#include <databasecontroller.h>
using namespace std;

class Request{

    public:
            Request(string m,QTcpSocket* client,DatabaseController &db);
            virtual void respond(QTcpSocket* client,DatabaseController &db)= 0;

    private:
           string msg;

};
#endif // REQUEST_H
