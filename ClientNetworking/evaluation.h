#ifndef EVALUATION_H
#define EVALUATION_H

class Evaluation
{
public:
    Evaluation();
    std::string toString();
private:
    int rating;
    std::string comment;
    int id;
};

#endif // EVALUATION_H
