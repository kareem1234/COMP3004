#ifndef INSTRUCTORCLIENT_H
#define INSTRUCTORCLIENT_H
#include <course.h>
#include <ta.h>
#include <instructor.h>
#include <course.h>
#include <task.h>
#include <evaluation.h>
#include "clientUser.h"

using namespace std;

class instructorClient : public clientUser{
    Q_OBJECT
    public:
            instructorClient( QTcpSocket *c,QObject* parent = 0);
            void saveTask(TA t, Task ts);
            void deleteTask(Task ts);
            void saveEval(TA t, Evaluation e);
            void deleteEval(Evaluation e);
            Evaluation getEval(Task t);
            vector<Task> getTaskListForCourse(TA t, Course c);
            vector<TA> getTAList(Course c);
            vector<Course> getCourseList(Instructor i);



};
#endif // INSTRUCTORCLIENT_H
