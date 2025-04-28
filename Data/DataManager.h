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
#include "../Pets/Pet.h"             
#include "../Tasks/TaskManager.h"  
#include <fstream> 
#include <vector>


namespace DataManager {
    bool loadData(std::string &userName, Pet &pet, TaskManager &tm);

    void saveData(const std::string &userName, const Pet &pet, const TaskManager &tm);

    void resetData(); 
}

#endif