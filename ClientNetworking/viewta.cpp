#include "viewta.h"
#include "ui_viewta.h"

ViewTA::ViewTA(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTA)
{
    ui->setupUi(this);
}


void ViewTA::addTAS(vector<string>  TANames){
<<<<<<< HEAD

    int length = TANames.size();

    for(int i = 0 ; i < length ; i++){
=======
    int size = TANames.size();
    for(int i = 0 ; i < size; i++){
>>>>>>> 9d28120ac430c33a0c5437c55e73429911b0c3c4
        label = new QLabel(QString::fromStdString(TANames.back()));
        TANames.pop_back();
        TALabels.push_back(label);
        ui->verticalLayout->addWidget(label);
    }
}

ViewTA::~ViewTA()
{
    delete ui;
}
