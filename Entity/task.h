#ifndef TASK_H
#define TASK_H

class Task
{
public:
    Task();
    std::string tostring ();
private:
    std::string type;
    std::string dueDate;
    std::string instructions;
    std::string progress;

};

#endif // TASK_H
