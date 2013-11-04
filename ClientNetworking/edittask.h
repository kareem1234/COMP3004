#ifndef EDITTASK_H
#define EDITTASK_H
#include <string.h>
#include <QDialog>

using namespace std;

namespace Ui {
class EditTask;
}

class EditTask : public QDialog
{
    Q_OBJECT
    
public:
    explicit EditTask(QWidget *parent = 0);
    void setBefore(string type,string date, string desc);
    void setAfter(string type,string date, string desc);
    void setPass(bool pass);
    ~EditTask();
    
private:
    Ui::EditTask *ui;



};

#endif // EDITTASK_H
