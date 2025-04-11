#ifndef TASK_H
#define TASK_H

#include <string>
using namespace std;

struct Task {
    string name;
    string type; // "academic" or "personal"
    bool completed;

    Task(string name="", string type="", bool completed = false);


};

#endif