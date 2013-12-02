#include "SystemController.h"
SystemController:: SystemController(QObject* parent){
        client = network.getUser();
}

SystemController::~SystemController(){
    network.deleteUser();
    delete ta;
}

void SystemController:: taStart(){
    TA t;
    //t.setEmail(logginmenu.getText());
    ta = new TAcontroller(network.getTa(),client->TLogin(t));

}
