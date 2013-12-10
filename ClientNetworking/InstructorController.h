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
    Course getSelectedCourse();
    TA getSelectedTA();
    Task getSelectedTask();

            InstructorWindow* iScreen;
            Instructor self;
            instructorClient* client;

            vector<Course> courseList;
            vector<TA> taList;
            vector<Task> taskList;
    signals:
            void logout();
    public slots:
            void updateCourseList();
            void logoutClicked();
            void updateTAList();
            void updateTaskList();
            void saveTaskChanges();//this is the slot that calls the save task function in the client after a local task variable is updated with new data
            void createEvaluation();
            void deleteTask();
            void createTaskButtonClicked();
            void viewTaskSlot();
          //  void createTaskSlot();
            void createEvaluationDialogSlot();
            void deleteEvaluationSlot();
            void editEvaluation();
};
#endif // INSTRUCTORCONTROLLER_H
