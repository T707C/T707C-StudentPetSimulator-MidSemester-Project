#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Task.h"
#include <vector>
using namespace std;


class TaskManager {
    private:
         vector<Task> tasks; // vector to store tasks

    public: 
        TaskManager(); // constructor to initialize the task manager
        void addTask(string name, string type); // method to add a task
        void removeTask(int index); // method to remove a task by index
        void markTaskCompleted(int index); // method to mark a task as completed
        void displayTasks(); // method to display all tasks
        void saveTasksToFile(string filename); // method to save tasks to a file
        void loadTasksFromFile(string filename); // method to load tasks from a file
        void clearTasks(); // method to clear all tasks
};

#endif 
