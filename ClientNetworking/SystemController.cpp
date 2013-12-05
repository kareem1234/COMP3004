#include "SystemController.h"
#include <iostream>
SystemController:: SystemController(QObject* parent){
       client = network.getUser();
       menu = new MainMenu();
       menu->show();
       this->connect(this->menu,SIGNAL(taLogin()),
                     this,SLOT(taStart()));
       this->connect(this->menu,SIGNAL(instructorLogin()),
                      this,SLOT(instructorStart()));
}

SystemController::~SystemController(){
    network.deleteUser();
    delete ta;
}

void SystemController:: menuStart(){
    network.deleteUser();
    client = network.getUser();
    if(ta != 0){
        delete ta;
        ta = 0;
    }
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
    network.deleteUser();
    t.setEmail(menu->getText().toStdString());
    menu->close();
    delete(menu);
    menu = 0;
    ta = new TAcontroller(network.getTa(),client->TLogin(t));

}

void SystemController::instructorStart(){
    cout<<"starting instructor"<<endl;
    network.deleteUser();
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

}
