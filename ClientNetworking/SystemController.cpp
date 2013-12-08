#include "SystemController.h"
#include <iostream>
SystemController:: SystemController(QObject* parent){
       client = network.getUser();
       menu = new MainMenu();
       ta = 0;
       instructor = 0;
       menu->show();
       this->connect(this->menu,SIGNAL(taLogin()),
                     this,SLOT(taStart()));

       this->connect(this->menu,SIGNAL(instructorLogin()),
                      this,SLOT(instructorStart()));
}

SystemController::~SystemController(){
    network.deleteUser();
}

void SystemController::del(){
    cout<<"deleting controllers"<<endl;
    cout<<"t is: "<<ta<<"i is: "<<instructor<<endl;
    if(ta != 0){
        delete ta;
        ta = 0;
    }

    if(instructor != 0){
        delete instructor;
        instructor = 0;
    }

}
void SystemController:: menuStart(){
    cout<<"starting menu"<<endl;
    network.deleteTa();
    network.deleteInstructor();
    del();
    client = network.getUser(); 
    cout<<"deleted ta pointer"<<endl;
    menu = new MainMenu();
    menu->show();
    this->connect(this->menu,SIGNAL(taLogin()),
                  this,SLOT(taStart()));
    this->connect(this->menu,SIGNAL(instructorLogin()),
                   this,SLOT(instructorStart()));
}
void SystemController:: taStart(){
    cout<<"starting ta"<<endl;
    TA t;
    //network.deleteUser();
    t.setEmail(menu->getText().toStdString());
    cout<<"email is: "<<menu->getText().toStdString()<<endl;
    menu->close();
    delete(menu);
    menu = 0;
    ta = new TAcontroller(network.getTa(),client->TLogin(t));
    this->connect(ta,SIGNAL(logout()),this,SLOT(menuStart()));
    network.deleteUser();
}

void SystemController::instructorStart(){
    cout<<"starting instructor"<<endl;
   //network.deleteUser();
    menu->close();
    Instructor i;
    i.setEmail(menu->getText().toStdString());
    menu->close();
    delete(menu);
    menu = 0;
    instructor = new InstructorController(network.getInstructor(),
                    client->ILogin(i));
    this->connect(this->instructor,SIGNAL(logout()),
                  this,SLOT(menuStart()));
    network.deleteUser();

}
