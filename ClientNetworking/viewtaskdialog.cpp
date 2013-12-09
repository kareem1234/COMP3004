#include "viewtaskdialog.h"
#include "ui_viewtaskdialog.h"
#include "task.h"

ViewTaskDialog::ViewTaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTaskDialog)
{


    ui->setupUi(this);
//Setting the time combo box values
    for(int i = 1 ; i < 25; i++){

        QString temp1;
        temp1 = QString::number(i);
        this->ui->timeComboBox1->addItem(temp1);

    }
//Setting the initial day combo box value
    for(int i = 1 ; i < 31; i++){

        QString temp1;
        temp1 = QString::number(i);
        this->ui->dayComboBox->addItem(temp1);

    }

    this->connect(this->ui->monthComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(setAmountOfDays()));
    this->connect(this->ui->pushButton,SIGNAL(clicked()),this,SLOT(confirmSave()));
    createTask = ui->pushButton;
}

void ViewTaskDialog::confirmSave()
{

    QMessageBox msgBox;
    msgBox.setText("The changes are about to be saved.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save |  QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    if(ret ==QMessageBox::Save){
        emit saveChanges();
    }
    QString taskDay = ui->dayComboBox->currentText();
    QString taskMonth = ui->monthComboBox->currentText();
}


ViewTaskDialog::~ViewTaskDialog()
{
    delete ui;
}




void ViewTaskDialog::setTaskDate(int taskMonth,int taskDay,int taskTimeHours,int taskTimeMinutes){

    ui->monthComboBox->setCurrentIndex(taskMonth-1);
    ui->dayComboBox->setCurrentIndex(taskDay-1);
    ui->timeComboBox1->setCurrentIndex(taskTimeHours-1);
    if(taskTimeHours<30)
    ui->timeComboBox2->setCurrentIndex(0);
    else
    ui->timeComboBox2->setCurrentIndex(1);
}


void ViewTaskDialog::setTaskDescription(QString description){

    ui->description->setText(description);

}

void ViewTaskDialog::setTaskNameTag(QString name){
    ui->taskNameLabel->setText(name);
}


void ViewTaskDialog::getTaskAtributes(Task* t){
   // QString taskName,taskHour,taskMinute,taskDay,taskMonth;
    t->setType( ui->taskNameLabel->text().toStdString() );
    t->setDueDate(ui->timeComboBox1->currentText().toStdString()+" "+
                  ui->timeComboBox2->currentText().toStdString()+" "+
                  ui->dayComboBox->currentText().toStdString()+" "+
                  ui->monthComboBox->currentText().toStdString());
    t->setInstructions(ui->description->toPlainText().toStdString());
}

//This function sets the proper amount of days in the dayComboBox for each month selected
void ViewTaskDialog::setAmountOfDays(){


    int i =1;
    this->ui->dayComboBox->clear();
    int k = this->ui->monthComboBox->currentIndex();
    QString temp1;


    if(k == 1){
        for(int i = 1 ; i < 29; i++){

            temp1 = QString::number(i);
            this->ui->dayComboBox->addItem(temp1);

        }
    }


    else if(k%2 !=0 && k < 7 ){
        for(int i = 1 ; i < 31; i++){

            temp1 = QString::number(i);
            this->ui->dayComboBox->addItem(temp1);

        }
    }


    else if(k%2 ==0 && k > 7 ){
        for(int i = 1 ; i < 31; i++){

            temp1 = QString::number(i);
            this->ui->dayComboBox->addItem(temp1);

        }
    }

    else
        for(int i = 1 ; i < 32; i++){

            temp1 = QString::number(i);
            this->ui->dayComboBox->addItem(temp1);

        }

}






