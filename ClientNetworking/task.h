#ifndef TASK_H
#define TASK_H

class Task
{
public:
    Task();
    Task(int, int, int, std::string, std::string, std::string, std::string);
    Task(std::string);
    std::string toString ();

    //set methods
    void setId(int);
    void setTaId(int);
    void setCourseId(int);
    void setType(std::string);
    void setDueDate(std::string);
    void setInstructions(std::string);
    void setProgress(std::string);

    //get methods
    int         getId();
    int         getTaId();
    int         getCourseId();
    std::string getType();
    std::string getDueDate();
    std::string getInstructions();
    std::string getProgress();

private:
    int id;
    int taID;
    int courseId;
    std::string type;
    std::string dueDate;
    std::string instructions;
    std::string progress;

};

#endif // TASK_H
