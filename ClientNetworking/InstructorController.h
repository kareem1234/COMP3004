#ifndef INSTRUCTORCONTROLLER_H
#define INSTRUCTORCONTROLLER_H
#include <QObject>
#include <ta.h>
#include <course.h>
#include <task.h>
#include "instructor.h"
#include <evaluation.h>
#include "instructorClient.h"
#include "instructorwindow.h"

class InstructorController : public QObject{
    Q_OBJECT
    public:
    InstructorController(instructorClient* c,
                         Instructor i,
                         QObject * parent = 0);
    ~InstructorController();

    private:
            InstructorWindow* iScreen;
            Instructor self;
            instructorClient* client;
    signals:
            void logout();
    public slots:
            void updateCourseList();
            void logoutClicked();
            void updateTAList();
            void updateTaskList();
            void saveTaskChanges();//this is the slot that calls the save task function in the client after a local task variable is updated with new data
            void saveEvaluation();
            void deleteEvaluation();
            void deleteTask();
<<<<<<< HEAD
            void createTaskButtonClicked();
            void viewTaskSlot();
            void createTaskSlot();




=======
>>>>>>> 31b2458ffdcd1e011f33766ddd8807fe55fec853

};
#endif // INSTRUCTORCONTROLLER_H
