// DataManager.h
// ======== Data Management Module ========
// This header declares the DataManager namespace responsible for
// persisting and restoring application state to and from the local filesystem.
// It provides three key functions:
//   1. loadData:  Attempts to read saved user settings, pet stats, and task list.
//                 Returns true if data was successfully loaded (i.e., not first-run).
//   2. saveData:  Writes the current user info, pet stats, and task list to disk.
//   3. resetData: Deletes all saved files, effectively resetting the application state.

#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include <string>
#include "Pets/Pets.h"             
#include "Tasks/TaskManager.h"  
#include <fstream> 
#include <vector>


namespace DataManager {
    bool loadData(std::string &userName, Pet &pet, TaskManager &tm) {
        // Use proper file handling and Pet getters/setters
        std::ifstream userFile("data/user.txt");
        if (!userFile.is_open()) return false;

        std::getline(userFile, userName);
        userFile.close();

        std::ifstream petFile("data/pet.txt");
        if (!petFile.is_open()) return false;

        std::string petName, petType, line;
        int iq, love, exp, level;
        
        std::getline(petFile, petName);
        std::getline(petFile, petType);
        petFile >> iq >> love >> exp >> level;
        
        pet = Pet(petName, petType);
        pet.setIQ(iq);         // Use setters instead of direct access
        pet.setLove(love);
        pet.setEXP(exp);
        pet.setLevel(level);
        petFile.close();

        std::ifstream taskFile("data/tasks.txt");
        if (!taskFile.is_open()) return false;

        std::string taskLine;
        while (std::getline(taskFile, taskLine)) {
            size_t pos1 = taskLine.find(';');
            size_t pos2 = taskLine.find(';', pos1 + 1);
            
            std::string name = taskLine.substr(0, pos1);
            std::string type = taskLine.substr(pos1 + 1, pos2 - pos1 - 1);
            bool completed = (taskLine.substr(pos2 + 1) == "1");
            
            tm.addTask(name, type);  // Use proper addTask signature
            if (completed) tm.completeTask(name);
        }
        taskFile.close();
        return true;
    }

    void saveData(const std::string &userName, const Pet &pet, const TaskManager &tm) {
        // Use proper ofstream and Pet getters
        std::ofstream userFile("data/user.txt");
        if (userFile.is_open()) {
            userFile << userName << "\n";
            userFile.close();
        }

        std::ofstream petFile("data/pet.txt");
        if (petFile.is_open()) {
            petFile << pet.getName() << "\n"
                    << pet.getType() << "\n"
                    << pet.getIQ() << "\n"
                    << pet.getLove() << "\n"
                    << pet.getEXP() << "\n"
                    << pet.getLevel() << "\n";
            petFile.close();
        }

        std::ofstream taskFile("data/tasks.txt");
        if (taskFile.is_open()) {
            for (const auto& task : tm.getTasks()) {  // Add getTasks() to TaskManager
                taskFile << task.name << ";" 
                         << task.type << ";" 
                         << (task.completed ? "1" : "0") << "\n";
            }
            taskFile.close();
        }
    }

    void resetData() {
        remove("data/user.txt");
        remove("data/pet.txt");
        remove("data/tasks.txt");
    }
}

#endif