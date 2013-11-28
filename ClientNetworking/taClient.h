#ifndef TACLIENT_H
#define TACLIENT_H

#include <course.h>
#include <ta.h>
#include <instructor.h>
#include <course.h>
#include <task.h>
#include <evaluation.h>
using namespace std;

class taClient : public clientUser{
    Q_OBJECT
    public:
            taClient( QTcpSocket c,QObject* parent = 0);

};


#endif // TACLIENT_H
