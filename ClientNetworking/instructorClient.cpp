#include "instructorClient.h"
#include "Message.cpp"

instructorClient ::instructorClient(QTcpSocket *c, QObject *parent):
    clientUser(c, parent){}

void instructorClient::saveTask(TA t, Task ts){
    Message<TA,Task> m(Message<string,int>::saveTask ,t,ts);
    clientUser::sendData(m.toString());
    clientUser::emptyBuffer();
}
void instructorClient:: deleteTask(Task ts){
    Message<Task,string> m(Message<string,int>::deleteTask,ts);
    clientUser::sendData(m.toString());
    clientUser::emptyBuffer();
}

void instructorClient::saveEval(TA t, Evaluation e){
    Message<TA,Evaluation> m(Message<string,int>::saveEval ,t,e);
    clientUser::sendData(m.toString());
    clientUser::emptyBuffer();
}
void instructorClient::deleteEval(Evaluation e){
    Message<Evaluation,TA> m(Message<string,int>::deleteEval,e);
    clientUser::sendData(m.toString());
    clientUser::emptyBuffer();
}
Evaluation instructorClient:: getEval(Task t){
    Message<Task,string> m(Message<string,int>::getEval,t);
    clientUser::sendData(m.toString());
    Message<Evaluation,string> rm(clientUser::read());
    Evaluation e(rm.returnA());
    return e;
}

vector<Task> instructorClient:: getTaskListForCourse(TA t, Course c){
    Message<TA,Course> m(Message<string,int>::viewTaskListForCourse,t,c);
    clientUser::sendData(m.toString());
    Message<Task,string> rm(clientUser::read());
    return rm.returnAvec();
}
vector<TA> instructorClient::getTAList(Course c){
    Message<Course,string> m(Message<string,int>::viewTaList,c);
    clientUser::sendData(m.toString());
    Message<TA,string> rm(clientUser::read());
    return rm.returnAvec();
}
vector<Course> instructorClient::getCourseList(Instructor i){
    Message<Instructor,string> m(Message<string,int>::viewCourseList,i);
    clientUser::sendData(m.toString());
    Message<Course,string> rm(clientUser::read());
    return rm.returnAvec();
}
