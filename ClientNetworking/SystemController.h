#ifndef SYSTEMCONTROLLER_H
#define SYSTEMCONTROLLER_H
#include "clientNetwork.h"
#include "TAcontroller.h"
using namespace std;


class SystemController : public QObject{
    Q_OBJECT
    public:
        SystemController(QObject* parent = 0);
        ~SystemController();
        void taStart();
    private:
            clientNetwork network;
            clientUser* client;
            TAcontroller *ta;


};
#endif // SYSTEMCONTROLLER_H
