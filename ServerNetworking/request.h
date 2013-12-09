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
            Request(string m);
            virtual void respond(QTcpSocket* client,DatabaseController &db)= 0;

    protected:
           string msg;

};
#endif // REQUEST_H
