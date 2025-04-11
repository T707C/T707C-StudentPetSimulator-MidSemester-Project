#include "Task.h"

Task::Task(string name, string type, bool completed) {
    this->name = name;
    this->type = type;
    this->completed = completed;
}