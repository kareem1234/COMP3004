#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <iostream>
using namespace std;
MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    this->connect(this->ui->logIn,SIGNAL(clicked()),this,SLOT(logInButtonPressed()));
}


void MainMenu::logInButtonPressed(){
    QString text = ui->userType->currentText();
    if(text.compare("TA") == 0)
        emit taLogin();
    else
        emit instructorLogin();
}
QString MainMenu::getText(){
<<<<<<< HEAD
    return ui->userName->text();
=======
    cout<<ui->userName->text().toStdString()<<endl;
    return ui->userName->text();

>>>>>>> e0c8e54061e0449239da50987ea7eaed6cd3f80c
}
MainMenu::~MainMenu()
{
    delete ui;
}
