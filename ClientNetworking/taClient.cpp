
#include "taClient.h"
#include "Message.cpp"

taClient:: taClient(QTcpSocket*c, QObject *parent):
    clientUser(c){}


Course taClient:: getCurrentCourse(TA self){
    Message<TA,string> m(Message<string,int>::getCurrentCourse,self);
    clientUser::sendData(m.toString());
    Message<Evaluation,string> rm(clientUser::read());
    Course c(rm.returnA());
    return c;
}

vector<Task> taClient:: getTaskListForCourse(TA self, Course c){
    Message<TA,Course> m(Message<string,int>::viewTaskListForCourse,self,c);
    clientUser::sendData(m.toString());
    Message<Task,string> rm(clientUser::read());
    return rm.returnAvec();
}

Evaluation taClient:: getEval(Task t){
    Message<Task,string> m(Message<string,int>::getEval,t);
    clientUser::sendData(m.toString());
    Message<Evaluation,string> rm(clientUser::read());
    Evaluation e(rm.returnA());
    return e;
}
