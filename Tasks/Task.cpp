// ======== Task Implementation ========
// Implements the Task constructor declared in Task.h.
// This file provides the initialization logic for Task objects,
// ensuring each Task starts with a defined name, category, and
// completion status.

#include "Task.h"

// Constructor definition:
//   - name: assigns the provided name string to the Task
//   - type: assigns the provided category/type string
//   - completed: sets the initial completion flag (false by default)
Task::Task(const string &name, const string &type, bool completed)
    : name(name), type(type), completed(completed) {}
