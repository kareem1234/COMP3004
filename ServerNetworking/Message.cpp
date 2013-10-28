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
            string getMethod();
            string toString();



};

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
string Message<A, B>:: getMethod(){
    return method;
}

template<class A, class B>
string Message<A, B>:: toString(){
  stringstream temp;
  temp << method;
  temp << obj1;
  temp << obj2;
  return temp.str();

}
