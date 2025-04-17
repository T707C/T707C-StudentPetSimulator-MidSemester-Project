// ======== TaskManager Implementation ========
// Implements the methods declared in TaskManager.h.
// Provides functionality to manage the lifecycle of tasks in-memory.

#include "TaskManager.h"
#include <iostream>      // For console output (std::cout)

// addTask: constructs a new Task and adds it to the tasks vector
void TaskManager::addTask(const string &name, const string &type) {
    tasks.emplace_back(name, type, false);
    cout << "[+] Task added: '" << name << "' (" << type << ")\n";
}

// viewTasks: lists all tasks, prefixing each with [x] or [ ]
void TaskManager::viewTasks() const {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    cout << "\n-- Current Tasks --\n";
    for (const auto &t : tasks) {
        cout << (t.completed ? "[x] " : "[ ] ")
             << t.name << " (" << t.type << ")\n";
    }
}

// completeTask: searches for a task by name and marks it completed
bool TaskManager::completeTask(const string &name) {
    for (auto &t : tasks) {
        if (t.name == name && !t.completed) {
            t.completed = true;
            cout << "[✔] Task completed: '" << name << "'\n";
            return true;
        }
    }
    cout << "[!] Task '" << name << "' not found or already completed.\n";
    return false;
}

// deleteTask: removes the first task matching the given name
bool TaskManager::deleteTask(const string &name) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->name == name) {
            tasks.erase(it);
            cout << "[-] Task deleted: '" << name << "'\n";
            return true;
        }
    }
    cout << "[!] Task '" << name << "' not found.\n";
    return false;
}
