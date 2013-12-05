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
    return ui->userName->selectedText();
}
MainMenu::~MainMenu()
{
    delete ui;
}
