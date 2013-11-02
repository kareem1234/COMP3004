#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

//template file
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
using namespace std;

class RequestHandler{

    public:
            RequestHandler(string m,QTcpSocket* client);
            void respond(QTcpSocket* client);

    private:
           string msg;
};

#endif // REQUESTHANDLER_H
