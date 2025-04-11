#include "TaskManager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#include "Task.h"


void TaskManager::addTask(const string& name, conststring& type) {
    tasks.push_back(Task(name, type));
    cout << "Task \" " << name << "\"added.\n"; 
}

void TaskManager::removeTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        cout << "Task at index " << index << " removed.\n";
    } else {
        cout << "Invalid index.\n";
    }
}

void TaskManager::markTaskCompleted(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
        cout << "Task at index " << index << " marked as completed.\n";
    } else {
        cout << "Invalid index.\n";
    }
}

void TaskManager::displayTasks() {
    cout << "Tasks:\n";
    for (int i = 0; i < tasks.size(); ++i) {
        cout << i << ": " << tasks[i].name << " (" << tasks[i].type << ") - "
             << (tasks[i].completed ? "Completed" : "Not Completed") << "\n";
    }
}


void TaskManager::saveTasksToFile(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& task : tasks) {
            file << task.name << "," << task.type << "," << task.completed << "\n";
        }
        file.close();
        cout << "Tasks saved to " << filename << ".\n";
    } else {
        cout << "Unable to open file.\n";
    }
}


void TaskManager::loadTasksFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        tasks.clear(); // Clear existing tasks
        string line;
        while (getline(file, line)) {
            string name, type;
            bool completed;
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            name = line.substr(0, pos1);
            type = line.substr(pos1 + 1, pos2 - pos1 - 1);
            completed = (line.substr(pos2 + 1) == "1");
            tasks.push_back(Task(name, type, completed));
        }
        file.close();
        cout << "Tasks loaded from " << filename << ".\n";
    } else {
        cout << "Unable to open file.\n";
    }
}

void TaskManager::clearTasks() {
    tasks.clear();
    cout << "All tasks cleared.\n";
}

