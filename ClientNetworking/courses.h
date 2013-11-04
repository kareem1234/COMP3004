#ifndef COURSES_H
#define COURSES_H
#include <QLabel>
#include <QDialog>
#include <string.h>
#include <vector>


using namespace std;

namespace Ui {
class Courses;
}

class Courses : public QDialog
{
    Q_OBJECT
    
public:
    explicit Courses(QWidget *parent = 0);
    void setLabels(string courses[5]);
    void setPassTag(bool pass);
    QLabel *label;
    vector<QLabel*> courseLabels;
    ~Courses();
    
private:
    Ui::Courses *ui;
};

#endif // COURSES_H
