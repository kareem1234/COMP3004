#ifndef TAREQUEST_H
#define TAREQUEST_H
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

class taRequest : public Request{

    public:
            taRequest(string m);
             void respond(QTcpSocket* client,DatabaseController &db);

};
#endif // TAREQUEST_H
