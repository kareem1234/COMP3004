
#include "taRequest.h"

taRequest::taRequest(string m, QTcpSocket *client, DatabaseController &db)
    :Request( m, client, db){}

void taRequest::respond(QTcpSocket *client, DatabaseController &db){
    string method = Message<string,int>::getMethod(msg);



    if(method.compare(Message<string,int>::viewTaskListForCourse)==0){
         Message<TA,Course> m(msg);
         Course c(m.returnB());
         TA t(m.returnA());
         vector<Task> mytasks = db.getTaskListForTACourse(t,c);
         Message<Task,string> f(mytasks);
         string s = f.toString();
         cout<<"sending back message: "<<s<<endl;
         client->write(s.c_str(),1000);
         return;



    }else if (method.compare(Message<string,int>::getTa)==0){
         Message<TA,string> m(msg);
         TA myTa(m.returnA());
         TA newT = db.loginTA(myTa.getEmail());
         Message<TA,string> f(newT.toString());
         string s = f.toString();
         cout<<"sending back message: "<<s<<endl;
         client->write(s.c_str(),1000);



   }else if (method.compare(Message<string,int>::getCurrentCourse)==0){
        Message<TA,string> m(msg);
        TA t(m.returnA());
        Course c = db.getCurrentCourse(t);
        Message<TA,string> f(c.toString());
        string s = f.toString();
        cout<<"sending back message: "<<s<<endl;
        client->write(s.c_str(),1000);

   }
}
