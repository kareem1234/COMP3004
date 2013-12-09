#ifndef INSTRUCTORREQUEST_H
#define INSTRUCTORREQUEST_H
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
#include "request.h"
using namespace std;

class instructorRequest : public Request{

    public:
            instructorRequest(string m);
             void respond(QTcpSocket* client,DatabaseController &db);



};
#endif // INSTRUCTORREQUEST_H
