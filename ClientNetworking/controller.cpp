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
    view.createTask(t.getDueDate(),t.getType(),t.getInstructions());
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
    Evaluation e(5,0,1,"well done");
    connection.saveEval(mary,e);
    view.evaluationSaveView->setEvaluation(toString(e.getRating()),e.getComment(),toString(e.getId()));
}

void Controller:: editEvaluation(){
    cout<<"in this function2"<<endl;
    count ++;
    stringstream edited;
    edited<<"Edited " <<count<<" times"<<endl;
    string s = edited.str();
    TA mary(1,1,"Mary Sue",4.0,"mary.sue@carleton.ca",100869040);

    // create a new evaluation object
    Evaluation e(5,1,1,s);

    // send the new evaluation object to the server
    connection.saveEval(mary,e);

    Task task(1, 1, 1, "assignment", "Wednesday", "Mark assignment 2", "In Progress");

    // get the created evaluation back from the database
    Evaluation savedEval = connection.getEval(task);
    view.evaluationSaveView->setEvaluation(toString(savedEval.getRating()),savedEval.getComment(),toString(savedEval.getId()));
}

void Controller:: deleteEvaluation(){
    cout<<"in this function1"<<endl;
    Evaluation e(5,1,1,"well done");
    connection.deleteEval(e);
    view.evaluationSaveView->setEvaluation("","","");
}

void Controller::deleteTask(){
    Task t(1, 1, 1,"office hours","today","actually come to office hours","Not done");
    connection.deleteTask(t);
    ///do stuff

}


void Controller::viewTA()
{  Instructor i(1, "Joe Teacher","joeteach@carletoncal",
                "HP5120", "CS");
    vector<Course> courses = connection.getCourseList(i);
    vector<string> TANames;
    vector<TA> tas = connection.getTAList(courses[0]);
    for(int i=0;i<tas.size();i++)
        TANames.push_back(tas[i].getName());

    view.viewTA(TANames);
}

void Controller:: viewTask(){
    Instructor i(1, "Joe Teacher","joeteach@carletoncal",
                          "HP5120", "CS");
    vector<Course> courses = connection.getCourseList(i);
    TA mary(1,1,"Mary Sue",4.0,"mary.sue@carleton.ca",100869040);
    vector<Task> t =connection.getTaskListForCourse(mary,courses[0]);
    vector<string> taskNames;
    for(int z=0;z<t.size();z++)
        taskNames.push_back(t[0].getType());
    view.viewTasks(taskNames);
}

void Controller::editTask(){
    Instructor i(1, "Joe Teacher","joeteach@carletoncal",
                          "HP5120", "CS");
    vector<Course> courses = connection.getCourseList(i);
    TA mary(1,1,"Mary Sue",4.0,"mary.sue@carleton.ca",100869040);
    vector<Task> t =connection.getTaskListForCourse(mary,courses[0]);
    Task oldtask(t[0].toString());
    Task newTask(t[0].toString());
    newTask.setDueDate("never");
    connection.saveTask(mary,newTask);
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

