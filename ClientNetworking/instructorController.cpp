
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
    connect(this->iScreen,SIGNAL(createEvaluationSignal()),this,SLOT(createEvaluationDialogSlot()));
    iScreen->show();
    cout<<"instructor is: "<<self.toString();

    iScreen->updateEmailLabel(QString::fromStdString(self.getEmail()));

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
    Course c = getSelectedCourse();

    TA t = getSelectedTA();

    taskList = client->getTaskListForCourse(t,c);

    vector<QString> tStrings;
    for(int i = taskList.size()-1; i >= 0; i-- ){
       QString t = QString::fromStdString(taskList[i].getType());
        tStrings.push_back(t);
    }
    iScreen->refreshList(tStrings,"task");

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
    iScreen->disableButtons();
}

void InstructorController::createEvaluation(){
    QMessageBox msgBox;
    msgBox.setText("You are about to create an evaluation.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save |  QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    if(ret ==QMessageBox::Save){

        Task tas = getSelectedTask();
        Evaluation e;
        int taskId = tas.getId();
        e.setTaskId(taskId);
        iScreen->saveEvaluation(&e);
        e.setId(0);
        client->saveEval(getSelectedTA(),e);
        iScreen->evaluationDialog->close();
    }
}

void InstructorController::saveTaskChanges(){

    Task tas = getSelectedTask();
    iScreen->saveTask(&tas);

    //save task in database
    client->saveTask(getSelectedTA(), tas);

    updateTaskList();
    iScreen->disableButtons();
}


void InstructorController::createTaskButtonClicked(){
    iScreen->createTaskDialog();
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

    if (tr == -1)
    {
        Task t;
        t.setId(0);
        return t;
    }
    else
    {
        return taskList[tr];
    }

}


void InstructorController::createEvaluationDialogSlot(){

    Task tas = getSelectedTask();
    Evaluation e = client->getEval(tas);
    iScreen->evaluationDialog= new EvaluationDialog();
    this->connect(iScreen->evaluationDialog->deleteButton,SIGNAL(clicked()),this,SLOT(deleteEvaluationSlot()));
    this->connect(iScreen->evaluationDialog->saveButton,SIGNAL(clicked()),this,SLOT(createEvaluation()));
    this->connect(iScreen->evaluationDialog->editButton,SIGNAL(clicked()),this,SLOT(editEvaluation()));

    if(e.getId() != -1){

        iScreen->evaluationDialog->saveButton->setEnabled(false);
        iScreen->evaluationDialog->editButton->setEnabled(true);
        iScreen->evaluationDialog->deleteButton->setEnabled(true);
        iScreen->evaluationDialog->comments->setText(QString::fromStdString(e.getComment()));
        iScreen->evaluationDialog->grade->setCurrentIndex(e.getRating()-1);
        iScreen->evaluationDialog->passLabel->setText("True");

    }

    iScreen->evaluationDialog->show();

}


void InstructorController::deleteEvaluationSlot(){
    QMessageBox msgBox;
    msgBox.setText("You are about to delete the evaluation for this task.");
    msgBox.setInformativeText("Would you like to proceed?");
    msgBox.setStandardButtons(QMessageBox::Ok|  QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
    if(ret ==QMessageBox::Ok){

        Task t = getSelectedTask();
        Evaluation e = client->getEval(t);
        client->deleteEval(e);
        iScreen->evaluationDialog->close();

    }
}

void InstructorController::editEvaluation(){
    QMessageBox msgBox;
    msgBox.setText("The changes are about to be saved.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save |  QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    if(ret ==QMessageBox::Save){
        Task tas = getSelectedTask();
        Evaluation e = client->getEval(tas);
        iScreen->saveEvaluation(&e);
        client->saveEval(getSelectedTA(),e);
        iScreen->evaluationDialog->close();
    }


}
