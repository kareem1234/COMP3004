#include <QtGui/QApplication>
#include <SystemController.h>.

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SystemController c; 
    return a.exec();
}
