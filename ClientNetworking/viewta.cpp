#include "viewta.h"
#include "ui_viewta.h"

ViewTA::ViewTA(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTA)
{
    ui->setupUi(this);
}


void ViewTA::addTAS(vector<string>  TANames){
    int size = TANames.size();
    for(int i = 0 ; i < size; i++){
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
