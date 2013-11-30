#include "tamainscreen.h"
#include "ui_tamainscreen.h"

TAMainScreen::TAMainScreen(QWidget *parent) : QFrame(parent), ui(new Ui::TAMainScreen)
{
    ui->setupUi(this);
    this->ui->taskItems->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->ui->taskItems->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->ui->taskItems->setSelectionMode(QAbstractItemView::SingleSelection);
    this->ui->taskItems->setShowGrid(false);
    this->connect(this->ui->taskItems, SIGNAL(cellClicked(int, int)),this, SLOT( cellSelected(int, int) ) );
}


TAMainScreen::~TAMainScreen()
{
    delete ui;
}

void TAMainScreen::initTA(std::string email, std::string course){
    this->ui->userName->setText(QString::fromStdString(email));
    this->ui->courseAssigned->setText(QString::fromStdString(course));
}

void TAMainScreen::setTable(std::vector<Task> t){

    for(size_t i = 0; i < t.size(); i++){
        QTableWidgetItem *item1 = new QTableWidgetItem(t.at(i).getId());
        QTableWidgetItem *item2 = new QTableWidgetItem(QString::fromStdString(t.at(i).getDueDate()));
        this->ui->taskItems->setItem(i, 0, item1);
        this->ui->taskItems->setItem(i, 1, item2);
    }
}

void TAMainScreen::cellSelected(int r, int c){
    emit cellSelectedSignal(r,c);
}

void TAMainScreen::displayEvaluation(std::string eval){
    this->ui->evaluation->setText(QString::fromStdString(eval));
}
void TAMainScreen::displayDetails(std::string details){
    this->ui->details->setText(QString::fromStdString(details));
}
