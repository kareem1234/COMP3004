#include "requesthandler.h"

RequestHandler::RequestHandler(string m,QTcpSocket* client){
     msg =m;
     respond(client);
}

void RequestHandler::respond(QTcpSocket* client){
   string method = Message<string,int>::getMethod(msg);

   if(method.compare(Message<string,int>::saveTask) == 0 ){
       Message<TA,Task> m(msg);
       TA t(m.returnA());
       Task tas(m.returnB());
       //call database method , create message with return objects then return message.tostring

   }else if(method.compare(Message<string,int>::deleteTask) == 0 ){
        Message<Task,string> m(msg);
        Task t(m.returnA());
        //call database method , create message with return objects then return message.tostring

   }else if(method.compare(Message<string,int>::saveEval)== 0){
        Message<TA,Evaluation> m(msg);
        TA t(m.returnA());
        Evaluation(m.returnB());
         //call database method , create message with return objects then return message.tostring

   }else if(method.compare(Message<string,int>::deleteEval) == 0){
        Message<Evaluation,string> m(msg);
        Evaluation e(m.returnA());
        //call database method , create message with return objects then return message.tostring

   }else if(method.compare(Message<string,int>::getEval)==0){
        Message<Evaluation,string> m(msg);
        Evaluation e(m.returnA());
        //call database method , create message with return objects then return message.tostring

   }else if(method.compare(Message<string,int>::viewTaskListForCourse)==0){
        Message<TA,Course> m(msg);
        Course c(m.returnB());
        TA t(m.returnA());
        //call database method , create message with return objects then return message.tostring

   }else if(method.compare(Message<string,int>::viewTaList)==0){
       Message<Course,string> m(msg);
       Course c(m.returnA());
         //call database method , create message with return objects then return message.tostring

   }else if(method.compare(Message<string,int>::viewCourseList)==0){
        Message<Instructor,string> m(msg);
        Instructor teacher(m.returnA());
        //call database method , create message with return objects then return message.tostring
  }

}
