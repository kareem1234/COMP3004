#ifndef EVALUATION_H
#define EVALUATION_H

class Evaluation
{
public:
    Evaluation();
    Evaluation(std::string);
    std::string toString();
private:
    int rating;
    int id;
    int taskID;
    std::string comment;
};

#endif // EVALUATION_H
