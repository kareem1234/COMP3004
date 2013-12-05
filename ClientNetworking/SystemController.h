#ifndef SYSTEMCONTROLLER_H
#define SYSTEMCONTROLLER_H
#include "clientNetwork.h"
#include "TAcontroller.h"
#include "InstructorController.h"
#include "mainmenu.h"
using namespace std;


class SystemController : public QObject{
    Q_OBJECT
    public:
        SystemController(QObject* parent = 0);
        ~SystemController();
    public slots:
        void taStart();
        void instructorStart();
        void menuStart();
    private:
            clientNetwork network;
            clientUser* client;
            TAcontroller *ta;
            InstructorController *instructor;
            MainMenu* menu;


};
#endif // SYSTEMCONTROLLER_H
