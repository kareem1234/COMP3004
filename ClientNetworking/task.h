#ifndef TASK_H
#define TASK_H

class Task
{
public:
    Task();
    std::string toString ();
private:
    std::string type;
    std::string dueDate;
    std::string instructions;
    std::string progress;
    int ID;


};

#endif // TASK_H
