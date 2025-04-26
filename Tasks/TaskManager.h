// ======== TaskManager Interface ========
// Declares the TaskManager class, which maintains a collection of Task objects
// and provides methods to add, view, complete, and delete tasks.
// This serves as the core of the CLI Task Manager system.

#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "Task.h"         // Definition of the Task struct
#include <vector>          // For std::vector container
using namespace std;

class TaskManager {
private:
    vector<Task> tasks;    // Internal storage of all tasks

public:
    // addTask: create a new Task with given name and type, append to list
    void addTask(const string &name, const string &type);

    // viewTasks: display all tasks, including their completion status
    void viewTasks() const;

    // completeTask: mark the first matching Task name as completed
    // returns true if the task was found and marked, false otherwise
    bool completeTask(const string &name);

    // deleteTask: remove the first matching Task by name
    // returns true if the task was found and deleted, false otherwise
    bool deleteTask(const string &name);

    const vector<Task>& getTasks() const { return tasks; }
};

#endif 
