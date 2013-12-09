
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
    this->connect(this->iScreen,SIGNAL(saveTaskSignal()),this,SLOT(saveTaskChanges()));
    this->connect(this->iScreen->createTaskButton,SIGNAL(clicked()),this,SLOT(createTaskButtonClicked()));
    this->connect(this->iScreen,SIGNAL(viewTaskSignal()),this,SLOT(viewTaskSlot()));
    connect(this->iScreen,SIGNAL(createEvaluationSignal()),this,SLOT(createEvaluationDialogSlot()));
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
    vector<Course> courses = client->getCourseList(self);
    vector<QString> cStringList;
    for(int i= courses.size()-1; i>= 0; i--){
        cStringList.push_back(QString::fromStdString(courses[i].getCourseName()));
    }
    iScreen->refreshList(cStringList,"course");
}

void InstructorController:: updateTAList(){
    vector<Course> courses = client->getCourseList(self);
    vector<TA>  allTas = client->getTAList(courses[iScreen->getCRow()]);
    vector<QString> taStringList;

    for(int i = allTas.size() - 1; i>= 0; i--) {
       QString title = QString::fromStdString(allTas[i].getName());
       taStringList.push_back(title);
    }

    iScreen->refreshList(taStringList,"TA");
}

void InstructorController:: updateTaskList(){
    int tr = iScreen->getTRow();
    int cr = iScreen->getCRow();
    vector<Course> courses = client->getCourseList(self);
    Course c = courses[cr];
    TA t = client->getTAList(c)[tr];
    cout<<"THIS TA IS: "<<t.toString();
    vector<Task> tasks = client->getTaskListForCourse(t,c);
    vector<QString> tStrings;
    for(int i = tasks.size()-1; i >= 0; i-- ){
       QString t= QString::fromStdString(tasks[i].getType());
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

void InstructorController::createEvaluation(){


    int tr = iScreen->getTRow();
    int cr = iScreen->getCRow();
    Course c = client->getCourseList(self)[cr];
    TA t = client->getTAList(c)[tr];
    int row = iScreen->myList->currentRow();
    Task tas = client->getTaskListForCourse(t,c)[row];
    Evaluation e;
    int taskId = tas.getId();
    e.setTaskId(taskId);
    iScreen->saveEvaluation(&e);
    e.setId(0);
    client->saveEval(t,e);

}

void InstructorController::saveTaskChanges(){

    int tr = iScreen->getTRow();
    int cr = iScreen->getCRow();
    Course c = client->getCourseList(self)[cr];
    TA t = client->getTAList(c)[tr];
    int row = iScreen->myList->currentRow();
    Task tas = client->getTaskListForCourse(t,c)[row];
    iScreen->saveTask(&tas);
    //save task in database
}


void InstructorController::createTaskButtonClicked(){


    iScreen->createTaskDialog();
    connect(this->iScreen->taskDialog->createTask,SIGNAL(clicked()),this,SLOT(createTaskSlot()));


}

void InstructorController::createTaskSlot(){

    Task t;
    int tr = iScreen->getTRow();
    int cr = iScreen->getCRow();
    iScreen->saveTask(&t);
    Course c = client->getCourseList(self)[cr];
    TA tA = client->getTAList(c)[tr];
    client->saveTask(tA,t);
    updateTaskList();

}


void InstructorController::viewTaskSlot(){

    iScreen->taskDialog = new ViewTaskDialog();
    iScreen->taskDialog->setModal(true);
    connect(iScreen->taskDialog,SIGNAL(saveChanges()),iScreen,SLOT(saveTaskSignalSlot()));
    iScreen->taskDialog->exec();



}


void InstructorController::createEvaluationDialogSlot(){

    int tr = iScreen->getTRow();
    int cr = iScreen->getCRow();
    Course c = client->getCourseList(self)[cr];
    TA t = client->getTAList(c)[tr];
    int row = iScreen->myList->currentRow();
    Task tas = client->getTaskListForCourse(t,c)[row];
    Evaluation e = client->getEval(tas);
    iScreen->evaluationDialog= new EvaluationDialog();
    this->connect(iScreen->evaluationDialog->deleteButton,SIGNAL(clicked()),this,SLOT(deleteEvaluationSLot()));
    this->connect(iScreen->evaluationDialog->saveButton,SIGNAL(clicked()),this,SLOT(createEvaluation()));

    if(e.getId() != -1){

        iScreen->evaluationDialog->saveButton->setEnabled(false);
        iScreen->evaluationDialog->editButton->setEnabled(true);
        iScreen->evaluationDialog->deleteButton->setEnabled(true);
        iScreen->evaluationDialog->comments->setText(QString::fromStdString(e.getComment()));
        iScreen->evaluationDialog->grade->setCurrentIndex(e.getRating()-1);

    }

    iScreen->evaluationDialog->show();

}
