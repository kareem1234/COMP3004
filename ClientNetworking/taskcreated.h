#ifndef TASKCREATED_H
#define TASKCREATED_H

#include <QDialog>
#include <string.h>

namespace Ui {
class TaskCreated;
}

using namespace std;

class TaskCreated : public QDialog
{
    Q_OBJECT
    
public:
    explicit TaskCreated(QWidget *parent = 0);
    explicit TaskCreated(QWidget *parent = 0,string type=0,string date=0, string dsc=0);
    void setPassTag(bool pf);
    ~TaskCreated();
    
private:
    Ui::TaskCreated *ui;
};

#endif // TASKCREATED_H
