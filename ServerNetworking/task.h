#ifndef TASK_H
#define TASK_H

class Task
{
public:
    Task();
    Task(std::string);
    std::string toString ();
private:
    std::string type;
    std::string dueDate;
    std::string instructions;
    std::string progress;
    int id;
    int taID;


};

#endif // TASK_H
