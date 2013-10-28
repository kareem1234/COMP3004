#include "instructor.h"
#include "user.h"
#include "ta.h"
#include "course.h"
#include "evaluation.h"
#include "task.h"
#include <iostream>

using namespace std;

int main(){
    Instructor a ;
    TA b ;
    Course c;
    Task d;
    Evaluation e ;
    User f ;

    cout << a.tostring() <<endl;
    cout << b.tostring() <<endl;
    cout << c.tostring() <<endl;
    cout << d.tostring() <<endl;
    cout << e.tostring() <<endl;

    return 0;
}
