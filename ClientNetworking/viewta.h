#ifndef VIEWTA_H
#define VIEWTA_H

#include <QDialog>
#include <QLabel>
#include <vector>

using namespace std;

namespace Ui {
class ViewTA;
}

class ViewTA : public QDialog
{
    Q_OBJECT


    
public:
    explicit ViewTA(QWidget *parent = 0);
    vector<QLabel*> TALabels;
    QLabel *label;
    void addTAS(vector<string> TANames);
    ~ViewTA();
    
private:
    Ui::ViewTA *ui;
};

#endif // VIEWTA_H
