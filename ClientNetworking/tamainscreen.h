#ifndef TAMAINSCREEN_H
#define TAMAINSCREEN_H
#include <task.h>
#include <QFrame>

namespace Ui {
class TAMainScreen;
}

class TAMainScreen : public QFrame
{
    Q_OBJECT

public:
    explicit TAMainScreen(QWidget *parent = 0);
    ~TAMainScreen();
    void setTable(std::vector<Task>);
    void displayEvaluation(QString, QString);
    void displayDetails(QString instructions, QString type, QString progress);
    void initTA(std::string, std::string);
private:
    Ui::TAMainScreen *ui;
    std::vector<Task> t;


private slots:
    void logoutClicked();
    void cellSelected(int r, int c);
signals:
    void logout();
    void cellClicked();
    void cellSelectedSignal(int, int);
};

#endif // TAMAINSCREEN_H
