
#include "InstructorController.h"

#include <QDateTime>
#include <QDate>
#include <QTime>


InstructorController:: InstructorController(instructorClient *c,
Instructor i,QObject* parent): QObject(parent){
    self = i;
    iScreen = new InstructorWindow;
    client = c;
    this->connect(this->iScreen,SIGNAL(logOutInstructor()),this,SLOT(logoutClicked()));
    this->connect(this->iScreen,SIGNAL(updateTaskListSignal()),this,SLOT(updateTaskList()));
    this->connect(this->iScreen,SIGNAL(updateTAListSignal()),this,SLOT(updateTAList()));
    this->connect(this->iScreen,SIGNAL(deleteTaskSignal()),this,SLOT(deleteTask()));
    this->connect(this->iScreen,SIGNAL(saveTaskSignal()),this,SLOT(saveTaskChanges()));
    this->connect(this->iScreen->createTaskButton,SIGNAL(clicked()),this,SLOT(createTaskButtonClicked()));
    this->connect(this->iScreen,SIGNAL(viewTaskSignal()),this,SLOT(viewTaskSlot()));
    iScreen->show();
    cout<<"instructor is: "<<self.toString();
    updateCourseList();
}

InstructorController::~InstructorController(){
    cout<<"deleted instructor"<<endl;
    iScreen-> close();
    delete iScreen;
    iScreen = 0;
}

void InstructorController:: logoutClicked(){
    cout<<"logging out"<<endl;
    emit logout();

}

void InstructorController:: updateCourseList(){
    courseList = client->getCourseList(self);

    vector<QString> cStringList;
    for(int i= courseList.size()-1; i>= 0; i--){
        cStringList.push_back(QString::fromStdString(courseList[i].getCourseName()));
    }
    iScreen->refreshList(cStringList,"course");
}

void InstructorController:: updateTAList(){
    taList = client->getTAList(courseList[iScreen->getCRow()]);

    vector<QString> taStringList;

    for(int i = taList.size() - 1; i>= 0; i--) {
       QString title = QString::fromStdString(taList[i].getName());
       taStringList.push_back(title);
    }

    iScreen->refreshList(taStringList,"TA");
}

void InstructorController:: updateTaskList(){
    int tr = iScreen->getTRow();
    int cr = iScreen->getCRow();

    Course c = courseList[cr];

    TA t = taList[tr];

    cout<<"THIS TA IS: "<<t.toString();

    taskList = client->getTaskListForCourse(t,c);

    vector<QString> tStrings;
    for(int i = taskList.size()-1; i >= 0; i-- ){
       QString t = QString::fromStdString(taskList[i].getType());
        tStrings.push_back(t);
    }
    iScreen->refreshList(tStrings,"task");

}

void InstructorController::deleteEvaluation(){
    // not sure wat u want
}

void InstructorController::deleteTask(){

    int tr = iScreen->getTRow();
    int cr = iScreen->getCRow();
    Course c = client->getCourseList(self)[cr];
    TA t = client->getTAList(c)[tr];
    int row = iScreen->myList->currentRow();
    Task tas = client->getTaskListForCourse(t,c)[row];
    client->deleteTask(tas);

    updateTaskList();

}

void InstructorController::saveEvaluation(){
    // not sure what u want
}

void InstructorController::saveTaskChanges(){

    Task tas = getSelectedTask();
    iScreen->saveTask(&tas);

    //save task in database
    client->saveTask(getSelectedTA(), tas);

    updateTaskList();
}


void InstructorController::createTaskButtonClicked(){


    iScreen->createTaskDialog();
    connect(this->iScreen->taskDialog->createTask,SIGNAL(clicked()),this,SLOT(createTaskSlot()));


}

void InstructorController::createTaskSlot(){

    Task t;
    t.setId(0);
    iScreen->saveTask(&t);

    TA ta = getSelectedTA();

    client->saveTask(ta, t);
    updateTaskList();
}


void InstructorController::viewTaskSlot(){

    iScreen->taskDialog = new ViewTaskDialog();
    iScreen->taskDialog->setModal(true);
    connect(iScreen->taskDialog,SIGNAL(saveChanges()),iScreen,SLOT(saveTaskSignalSlot()));

    // Set the values of the task dialog
    Task task = getSelectedTask();

    iScreen->taskDialog->setTaskDescription(QString::fromStdString(task.getInstructions()));

    // Set the date and the time
    QDateTime dateTime = QDateTime::fromString(QString::fromStdString(task.getDueDate()), Qt::ISODate);

    QDate date = dateTime.date();
    QTime time = dateTime.time();

    iScreen->taskDialog->setTaskDate(date.month(), date.day(), time.hour(), time.minute());

    iScreen->taskDialog->setTaskNameTag(QString::fromStdString(task.getType()));

    iScreen->taskDialog->exec();
}

Course InstructorController::getSelectedCourse()
{
    int cr = iScreen->getCRow();

    return courseList[cr];
}

TA InstructorController::getSelectedTA()
{
    int tr = iScreen->getTRow();

    return taList[tr];
}

Task InstructorController::getSelectedTask()
{
    int tr = iScreen->getTaskRow();

    return taskList[tr];
}
