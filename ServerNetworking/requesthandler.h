#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

//template file
#include "Message.cpp"
#include <iostream>
#include <string>
#include <QtNetwork>
#include <QObject>
#include <QTcpSocket>

class RequestHandler{

    public:
            RequestHandler(string m);
            string respond(QTcpSocket* client);

    private:
           string msg;
};

#endif // REQUESTHANDLER_H
