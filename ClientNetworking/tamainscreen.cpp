#include "tamainscreen.h"
#include "ui_tamainscreen.h"

TAMainScreen::TAMainScreen(QWidget *parent) : QFrame(parent), ui(new Ui::TAMainScreen)
{
    ui->setupUi(this);
    this->connect(this->ui->pushButton,SIGNAL(clicked()),this,SLOT(logoutClicked()));
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
    this->ui->textEmail->setText(QString::fromStdString(email));
    this->ui->textCourse->setText(QString::fromStdString(course));
}

void TAMainScreen::setTable(std::vector<Task> tasks){
    ui->taskItems->setRowCount(tasks.size());

    for(size_t i = 0; i < tasks.size(); i++){
        Task task = tasks.at(i);

        QString taskType = QString::fromStdString(task.getType());
        QString taskDueDate = QString::fromStdString(task.getDueDate());

        QTableWidgetItem *item1 = new QTableWidgetItem(taskType);
        QTableWidgetItem *item2 = new QTableWidgetItem(taskDueDate);

        this->ui->taskItems->setItem(i, 0, item1);
        this->ui->taskItems->setItem(i, 1, item2);
    }
}

void TAMainScreen::cellSelected(int r, int c){
    emit cellSelectedSignal(r,c);
}

void TAMainScreen::logoutClicked(){
    emit logout();
}

void TAMainScreen::displayEvaluation(QString rating, QString comments){
    this->ui->textRating->setText(rating);

    this->ui->textComments->setText(comments);
}

void TAMainScreen::displayDetails(QString instructions, QString type, QString progress) {
    this->ui->textInstructions->setText(instructions);

    this->ui->textType->setText(type);

    this->ui->textProgress->setText(progress);
}
