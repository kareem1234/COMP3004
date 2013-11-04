#include "courses.h"
#include "ui_courses.h"



Courses::Courses(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Courses)
{

    ui->setupUi(this);
}

void Courses::setLabels(string courses[5]){

    for(int i = 0 ; i < 5; i++){

        label = new QLabel(QString::fromStdString(courses[i]));
        courseLabels.push_back(label);
        ui->verticalLayout->addWidget(label);

    }

}

void Courses::setPassTag(bool pass){

    if(pass==true){

        this ->  ui -> passTag ->setText("TRUE");

    }
    else{
        this ->  ui -> passTag ->setText("FALSE");
    }
}

Courses::~Courses()
{
    delete ui;
}
