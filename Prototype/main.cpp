#include <QtGui/QApplication>
#include <controller.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller cont;
    cont.view.show();
    
    return a.exec();
}
