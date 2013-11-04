#include "controller.h"

Controller::Controller(QObject *parent) :
    QObject(parent)
{
     count = 0;
     connection.start("127.0.0.1",8888);
    this->connect(&view,SIGNAL(taskCreateTaskButtonPressed()),this,SLOT(createTask()));
    this->connect(&view,SIGNAL(viewCoursesSignal()),this,SLOT(viewCourses()));
    this->connect(&view,SIGNAL(viewTASignal()),this,SLOT(viewTA()));
    this->connect(&view,SIGNAL( viewTasksSignal()),this,SLOT(viewTask()));
    this->connect(&view,SIGNAL( editTaskSignal()),this,SLOT(editTask()));
    this->connect(&view,SIGNAL( saveEvaluationSignal()),this,SLOT(saveEvaluation()));
    this->connect(&view,SIGNAL( createEval()),this,SLOT(createEvaluation()));
    this->connect(&view,SIGNAL( deleteEval()),this,SLOT(deleteEvaluation()));
    this->connect(&view,SIGNAL( editEval()),this,SLOT(editEvaluation()));
     this->connect(&view,SIGNAL( deleteTaskSignal()),this,SLOT(deleteTask()));
}


void Controller::createTask(){
    TA mary(1,1,"Mary Sue",4.0,"mary.sue@carleton.ca",100869040);
    Task t(0, 1, 1,"office hours","today","actually come to office hours","Not done");
    connection.saveTask(mary,t);
    view.createTask(t.getDueDate(),t.getType(),t.getInstructions(),true);
}

void Controller::viewCourses(){
    Instructor i(1, "Joe Teacher","joeteach@carletoncal",
                          "HP5120", "CS");
    vector<Course> courses = connection.getCourseList(i);
     string courseNames[5];
     for(int i =0; i< 5; i++)
         courseNames[i] = courses[i].getCourseName();
    view.viewCourses(courseNames,true);

}

void Controller:: createEvaluation(){
    cout<<"in this function3"<<endl;
    TA mary(1,1,"Mary Sue",4.0,"mary.sue@carleton.ca",100869040);
    Task t(1,1,1,"","","","");
    connection.saveTask(mary,t);
    Evaluation e(5,1,1,"well done"),b(3,2,2,"badbad");
    connection.saveEval(mary,e);
    e = connection.getEval(t);
    view.evaluationSaveView->setEvaluation(toString(e.getRating()),e.getComment(),toString(e.getId()));
}

void Controller:: editEvaluation(){
    cout<<"in this function2"<<endl;
    count ++;
    stringstream edited;
    edited<<"Eddidted" <<count<<"times"<<endl;
    string s = edited.str();
    TA bob(1,1,"Brodie Gallinger",4,"whatup@yo.com",100869790);
    Evaluation e(5,1,1,s);
    connection.saveEval(bob,e);
    view.evaluationSaveView->setEvaluation(toString(e.getRating()),e.getComment(),toString(e.getId()));
}

void Controller:: deleteEvaluation(){
    cout<<"in this function1"<<endl;
    Evaluation e(5,1,1,"well done");
    connection.deleteEval(e);
    view.evaluationSaveView->setEvaluation("","","");
}

void Controller::deleteTask(){
    TA mary(1,1,"Mary Sue",4.0,"mary.sue@carleton.ca",100869040);
    Instructor i(1, "Joe Teacher","joeteach@carletoncal",
                          "HP5120", "CS");
    vector<Course> courses = connection.getCourseList(i);
    vector<Task> t =connection.getTaskListForCourse(mary,courses[0]);
    if(t.size() > 0)
         connection.deleteTask(t[0]);
    ///do stuff

}


void Controller::viewTA()
{  Instructor i(1, "Joe Teacher","joeteach@carletoncal",
                "HP5120", "CS");
    vector<Course> courses = connection.getCourseList(i);
    vector<string> TANames;
    vector<TA> tas = connection.getTAList(courses[0]);
    for(int i=0;i<tas.size();i++)
        TANames.push_back(tas[0].getName());

    view.viewTA(TANames);

}

void Controller:: viewTask(){
    Instructor i(1, "Joe Teacher","joeteach@carletoncal",
                          "HP5120", "CS");
    vector<Course> courses = connection.getCourseList(i);
    TA mary(1,1,"Mary Sue",4.0,"mary.sue@carleton.ca",100869040);
    vector<Task> t =connection.getTaskListForCourse(mary,courses[0]);
    cout<<"size is:"<<t.size()<<endl;
    vector<string> taskNames;
    for(int z=0;z<t.size();z++){
        string task = "TASK ";
        task+=toString(t[z].getId());
        taskNames.push_back(task);
    }
    view.viewTasks(taskNames);
}

void Controller::editTask(){
   Instructor i(1, "Joe Teacher","joeteach@carletoncal",
                          "HP5120", "CS");
    vector<Course> courses = connection.getCourseList(i);
    TA mary(1,1,"Mary Sue",4.0,"mary.sue@carleton.ca",100869040);
    vector<Task> t =connection.getTaskListForCourse(mary,courses[0]);
    Task oldtask(t[0].toString());
    Task final (t[0].toString());
    final .setDueDate("forever");
    connection.saveTask(mary,final);
    vector<Task> tasklist = connection.getTaskListForCourse(mary,courses[0]);
    Task newTask = tasklist[0];
    view.editTask(oldtask.getType(),oldtask.getInstructions(),oldtask.getDueDate(),
                  newTask.getType(),newTask.getInstructions(),newTask.getDueDate(),true);
}



void Controller::saveEvaluation(){
   view.saveEvaluation();
}

string Controller::toString(int a){
    ostringstream ss;
         ss << a;
         return ss.str();
}

