#ifndef EVALUATION_H
#define EVALUATION_H
#include <string>

class Evaluation
{
public:
    Evaluation();
    Evaluation(std::string);

    //set methods
    void setRating(int);
    void setId(int);
    void setTaskId(int);
    void setComment(std::string);

    //get methods
    int         getRating();
    int         getId();
    int         getTaskId();
    std::string getComment();

    //toString method
    std::string toString();
private:
    int rating;
    int id;
    int taskID;
    std::string comment;
};

#endif // EVALUATION_H
