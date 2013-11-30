#include <QtGui/QApplication>
#include <TAcontroller.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TAcontroller cont;
    cont.taScreen.show();
    
    return a.exec();
}
