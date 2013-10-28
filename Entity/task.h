#ifndef TASK_H
#define TASK_H

class Task
{
public:
    Task();
    String toString ();
private:
    String type;
    String dueDate;
    String instructions;
    String progress;

};

#endif // TASK_H
