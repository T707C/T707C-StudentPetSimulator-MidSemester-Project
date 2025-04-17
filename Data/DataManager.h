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

namespace DataManager {

    /**
     * loadData
     * --------
     * Attempts to load persisted application state from disk.
     * Parameters:
     *   - userName: reference to string to populate with saved user name
     *   - pet: reference to Pet object to populate with saved pet data
     *   - tm: reference to TaskManager to populate with saved tasks
     * Returns:
     *   - true if all required files were found and loaded successfully
     *   - false if any file is missing or malformed (indicating first-run)
     * 
     * Implementation notes:
     *   - Check for existence of data/user.txt, data/pet.txt, data/tasks.txt.
     *   - If any file is missing, return false immediately.
     *   - Otherwise, open each file, parse line-by-line or value-by-value:
     *       * user.txt: single line containing the user's name.
     *       * pet.txt: lines for name, type, iq, love, exp, level.
     *       * tasks.txt: each line represents a Task record, e.g., "<name>;<type>;<completed>".
     *   - Trim whitespace and validate formats.
     */
    bool loadData(std::string &userName, Pet &pet, TaskManager &tm);

    /**
     * saveData
     * --------
     * Persists the current application state to disk.
     * Parameters:
     *   - userName: the user's name to save
     *   - pet: the current Pet object with stats to save
     *   - tm: the TaskManager whose task list to save
     * Returns: void
     * 
     * Implementation notes:
     *   - Create (or overwrite) data/user.txt and write userName on one line.
     *   - Create (or overwrite) data/pet.txt and write pet fields, one per line:
     *       name, type, iq, love, exp, level.
     *   - Create (or overwrite) data/tasks.txt, looping through tm's tasks:
     *       * For each Task, write: name + ";" + type + ";" + (completed?"1":"0") + '\n'.
     *   - Ensure directories exist; create data/ if necessary.
     */
    void saveData(const std::string &userName, const Pet &pet, const TaskManager &tm);

    /**
     * resetData
     * ---------
     * Deletes all persisted data files, resetting the application to first-run state.
     * Returns: void
     * 
     * Implementation notes:
     *   - Delete (or truncate) data/user.txt, data/pet.txt, data/tasks.txt.
     *   - If the data/ directory becomes empty, you may choose to delete it.
     *   - Handle filesystem errors gracefully and report to console.
     */
    void resetData();

} // namespace DataManager

#endif