#include "InstructorController.h"


InstructorController:: InstructorController(instructorClient *c,
Instructor i,QObject* parent): QObject(parent){
    self = i;
    iScreen = new InstructorWindow;
    client = c;
    this->connect(this->iScreen,SIGNAL(logOutInstructor()),this,SLOT(logoutClicked()));
    this->connect(this->iScreen,SIGNAL(updateTaskListSignal()),this,SLOT(updateTaskList()));
    this->connect(this->iScreen,SIGNAL(updateTAListSignal()),this,SLOT(updateTAList()));
    this->connect(this->iScreen,SIGNAL(deleteTaskSignal()),this,SLOT(deleteTask()));
    iScreen->show();
}
InstructorController::~InstructorController(){
    iScreen-> close();
    delete iScreen;
    iScreen = 0;
}

void InstructorController:: logoutClicked(){
    emit logout();

}

void InstructorController:: updateTAList(){
    vector<Course> courses = client->getCourseList(self);
    vector<TA> allTas;
    for(int i=0; i< courses.size(); i++){
        vector<TA>  tas = client->getTAList(courses[i]);
        for(int z = 0; z< tas.size(); z++){
            allTas.push_back(tas[z]);
        }
    }
    vector<QString> taStringList;
    for(int y = 0; y< allTas.size(); y++){
       QString title = QString::fromStdString(allTas[y].getName());
       taStringList.push_back(title);
    }

    iScreen->refreshList(taStringList,"TA");
}

void InstructorController:: updateTaskList(){
    int tr = iScreen->getTRow();
    int cr = iScreen->getCRow();
    Course c = client->getCourseList(self)[cr];
    TA t = client->getTAList(c)[tr];
    vector<Task> tasks = client->getTaskListForCourse(t,c);
    vector<QString> tStrings;
    for(int i = 0; i < tasks.size(); i++ ){
       QString t= QString::fromStdString(tasks[i].getType());
        tStrings.push_back(t);
    }
    iScreen->refreshList(tStrings,"task");

}

void InstructorController::deleteEvaluation(){
    // not sure wat u want
}

void InstructorController::deleteTask(){
    // not sure what u want
}

void InstructorController::saveEvaluation(){
    // not sure what u want
}

void InstructorController::saveTaskChanges(){
//   not sure wat u want
}