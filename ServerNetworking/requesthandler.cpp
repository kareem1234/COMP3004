#include "requesthandler.h"

RequestHandler::RequestHandler(string m){
     msg =m;
}

string RequestHandler::respond(QTcpSocket* client){
   string method = Message<string,int>::getMethod(msg);

   if(method.compare(Message<string,int>::saveTask) == 0 ){

   }else if(method.compare(Message<string,int>::deleteTask) == 0 ){


   }else if(method.compare(Message<string,int>::saveEval)== 0){


   }else if(method.compare(Message<string,int>::deleteEval) == 0){


   }else if(method.compare(Message<string,int>::viewEvals)==0){

   }else if(method.compare(Message<string,int>::viewTaskListForCourse)==0){

   }else if(method.compare(Message<string,int>::viewTaList)==0){

   }else if(method.compare(Message<string,int>::viewCourseList)==0){

  }

}
