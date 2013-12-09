
#include "instructorRequest.h".h"

instructorRequest::instructorRequest(string m)
    :Request( m){}

void instructorRequest::respond( QTcpSocket *client, DatabaseController &db){
    cout<<"responding"<<endl;
    cout<<"msg is: "<<msg<<endl;
    string method = Message<string,int>::getMethod(msg);
    cout<<"method was"<<method<<endl;

    if(method.compare(Message<string,int>::saveTask) == 0 ){
        cout<<"saving task"<<endl;
        Message<TA,Task> m(msg);
        TA t(m.returnA());
        Task tas(m.returnB());
        db.saveTask(t, tas);
        client->write("true",1000);
        return;
    }else if(method.compare(Message<string,int>::deleteTask) == 0 ){
         cout<<" deleting task"<<endl;
         Message<Task,string> m(msg);
         Task t(m.returnA());
         db.deleteTask(t);
         client->write("true",1000);
         return;
    }else if(method.compare(Message<string,int>::saveEval)== 0){
        cout<<"saving eval"<<endl;
         Message<TA,Evaluation> m(msg);
         TA t(m.returnA());
         Evaluation e(m.returnB());
         db.saveEvaluation(e);
         client->write("true",1000);
         return;

    }else if(method.compare(Message<string,int>::deleteEval) == 0){
        cout<<"deleting eval"<<endl;
         Message<Evaluation,string> m(msg);
         Evaluation e(m.returnA());
         db.deleteEvaluation(e);
         client->write("true",1000);
         return;


    }else if(method.compare(Message<string,int>::getEval)==0){
        cout<<"getting eval"<<endl;
         Message<Task,string> m(msg);
         Task t(m.returnA());
         Evaluation e = db.getEvaluation(t);
         Message<Evaluation,string> f(Message<string,int>::reTurn,e);
         string s = f.toString();
         cout<<"sending back message: "<<s<<endl;
         client->write(s.c_str(),1000);
         return;



    }else if(method.compare(Message<string,int>::viewTaList)==0){
        cout<<"getting talist"<<endl;
        Message<Course,string> m(msg);
        Course c(m.returnA());
        vector<TA> myTas = db.getTAList(c);
        Message<TA,string> f(myTas);
        string s = f.toString();
        cout<<"sending back message: "<<s<<endl;
        client->write(s.c_str(),1000);
        return;


    }else if(method.compare(Message<string,int>::viewCourseList)==0){
        cout<<"getting courselist"<<endl;
         Message<Instructor,string> m(msg);
         Instructor teacher(m.returnA());
         vector<Course> mycourses = db.getCourseList(teacher);
         Message<Course,string> f(mycourses);
         string s = f.toString();
         cout<<"sending back message: "<<s<<endl;
         client->write(s.c_str(),1000);
         return;


    }else if (method.compare(Message<string,int>::getInstructor)==0){
        cout<<"getting instructor"<<endl;
        Message<Instructor,string> m(msg);
        Instructor myInstruct(m.returnA());
        Instructor newT = db.loginInstructor(myInstruct.getEmail());
        Message<Instructor,string> f(newT.toString());
        string s = f.toString();
        cout<<"sending back message: "<<s<<endl;
        client->write(s.c_str(),1000);

   }
}
