#include "requesthandler.h"

RequestHandler::RequestHandler(string m,QTcpSocket* client,DatabaseController &db){
     msg =m;
     respond(client,db);
}

void RequestHandler::respond(QTcpSocket* client,DatabaseController &db){
   string method = Message<string,int>::getMethod(msg);

   if(method.compare(Message<string,int>::saveTask) == 0 ){
       Message<TA,Task> m(msg);
       TA t(m.returnA());
       Task tas(m.returnB());
       db.saveTask(t, tas);
       return;
   }else if(method.compare(Message<string,int>::deleteTask) == 0 ){
        Message<Task,string> m(msg);
        Task t(m.returnA());
        db.deleteTask(t);
        return;
   }else if(method.compare(Message<string,int>::saveEval)== 0){
        Message<TA,Evaluation> m(msg);
        TA t(m.returnA());
        Evaluation e(m.returnB());
        db.saveEvaluation(e);
        return;

   }else if(method.compare(Message<string,int>::deleteEval) == 0){
        Message<Evaluation,string> m(msg);
        Evaluation e(m.returnA());
        db.deleteEvaluation(e);
        return;


   }else if(method.compare(Message<string,int>::getEval)==0){
        Message<Evaluation,string> m(msg);
        Task t(m.returnA());
        Evaluation e = db.getEvaluation(t);
        Message<Evaluation,string> f(Message<string,int>::reTurn,e);
        string s = f.toString();
        cout<<"sending back message: "<<s<<endl;
        client->write(s.c_str(),1000);
        return;

   }else if(method.compare(Message<string,int>::viewTaskListForCourse)==0){
        Message<TA,Course> m(msg);
        Course c(m.returnB());
        TA t(m.returnA());
        vector<Task> mytasks = db.getTaskListForTACourse(t,c);
        Message<Task,string> f(mytasks);
        string s = f.toString();
        cout<<"sending back message: "<<s<<endl;
        client->write(s.c_str(),1000);
        return;


   }else if(method.compare(Message<string,int>::viewTaList)==0){
       Message<Course,string> m(msg);
       Course c(m.returnA());
       vector<TA> myTas = db.getTAList(c);
       Message<TA,string> f(myTas);
       string s = f.toString();
       cout<<"sending back message: "<<s<<endl;
       client->write(s.c_str(),1000);
       return;


   }else if(method.compare(Message<string,int>::viewCourseList)==0){
        Message<Instructor,string> m(msg);
        Instructor teacher(m.returnA());
        vector<Course> mycourses = db.getCourseList(teacher);
        Message<Course,string> f(mycourses);
        string s = f.toString();
        cout<<"sending back message: "<<s<<endl;
        client->write(s.c_str(),1000);
        return;
    }

}
