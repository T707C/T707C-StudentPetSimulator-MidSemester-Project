// ======== Task Definition ========
// This header defines the Task struct, representing a single user task
// with a name, category (type), and completion status.
// Tasks are the core units in our TaskManager system, allowing users
// to add, view, complete, and delete tasks from their productivity list.

#ifndef TASK_H
#define TASK_H

#include <string>  // For std::string
using namespace std;

// A single Task with a descriptive name, a category/type label, and a completion flag.
struct Task {
    string name;       // The descriptive name of the task, e.g. "Do homework"
    string type;       // Category label, e.g. "academic", "personal", "health"
    bool completed;    // Flag indicating whether the task has been completed

    // Constructor: initialize Task fields
    //   - name: the task's name
    //   - type: the category of the task
    //   - completed: initial completion status (defaults to false)
    Task(const string &name = "", const string &type = "", bool completed = false);
};

#endif 

