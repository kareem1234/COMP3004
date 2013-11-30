#ifndef TACLIENT_H
#define TACLIENT_H

#include <course.h>
#include <ta.h>
#include <instructor.h>
#include <course.h>
#include <task.h>
#include <evaluation.h>
#include "clientUser.h"
using namespace std;

class taClient : public clientUser{
    Q_OBJECT
    public:
            taClient( QTcpSocket *c,QObject* parent = 0);
            Course getCurrentCourse(TA self);
            Evaluation getEval(Task t);
            vector<Task> getTaskListForCourse(TA self, Course c);

};


#endif // TACLIENT_H
