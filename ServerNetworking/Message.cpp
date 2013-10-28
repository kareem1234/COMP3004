#include <iostream>
#include <sstream>

using namespace std;

template <class A, class B>
class Message{

    private:
            string method;
            string obj1;
            string obj2;
    public:
            Message(string m, A param1, B param2);
            Message(string m, A param1);
            Message(string m);
            static string getMethod(string s);
            string toString();

            // static methodtype  strings
            static string saveTask;
            static string deleteTask;


            static string saveEval;
            static string deleteEval;
            static string viewEvals;

            static string viewTaskListForCourse;
            static string viewTaList;
            static string viewCourseList;

};

/// static string definitions
template < class A, class B>
string Message<A,B>::saveTask ="STASK \n";

template < class A, class B>
string Message<A,B>::deleteTask ="DTASK \n";

template < class A, class B>
string Message<A,B>::saveEval ="SEVAL \n";

template < class A, class B>
string Message<A,B>::deleteEval ="DEVAL \n";

template < class A, class B>
string Message<A,B>::viewEvals ="VEVAL \n";

template < class A, class B>
string Message<A,B>::viewTaskListForCourse ="VTASKS \n";

template < class A, class B>
string Message<A,B>::viewTaList="VTAS \n";

template < class A, class B>
string Message<A,B>::viewCourseList ="VTAS \n";



template < class A, class B>
Message <A, B>:: Message(string m, A param1, B param2){
    obj1 = param1.toString();
    obj2 = param2.toString();
    method = m;
}
template < class A, class B>
Message <A, B>:: Message(string m, A param1){
    obj1 = param1.toString();
    obj2 = "";
    method = m;
}
template < class A, class B>
Message <A, B>:: Message(string m){
    stringstream temp;
    string t1;
    temp<<m;
    int i = 0;
    while(getline(temp,t1)){
        if(i== 0)
            method = temp;
        else if(i == 1)
            obj1 = temp;
        else if(i == 2)
            obj2 = temp;
        i++;
    }
}

template<class A, class B>
string Message<A, B>:: getMethod(string s){
    stringstream temp;
    temp<< s;
    string t1;
    getline(temp,t1);
    return t1;
}

template<class A, class B>
string Message<A, B>:: toString(){
  stringstream temp;
  temp << method;
  temp << obj1;
  temp << obj2;
  return temp.str();

}
