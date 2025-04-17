// ======== Data Management Module Implementation ========
// Implements the DataManager functions declared in DataManager.h
// This file contains stubs with detailed pseudocode comments indicating
// how to read/write the user, pet, and task data to local files.

#include "DataManager.h"
#include <fstream>      
#include <filesystem>   
#include <sstream>      /
#include <iostream>     

namespace DataManager {

bool loadData(std::string &userName, Pet &pet, TaskManager &tm) {
    // 1. Ensure data directory exists
    //    if (!std::filesystem::exists("data")) return false;

    // 2. Check existence of each required file
    //    if (!exists("data/user.txt") || !exists("data/pet.txt") || !exists("data/tasks.txt"))
    //        return false;  // First-run: no saved data

    // 3. Open user.txt and read the single line into userName
    //    std::ifstream userFile("data/user.txt");
    //    std::getline(userFile, userName);
    //    trimString(userName);

    // 4. Open pet.txt and read fields line by line:
    //    std::ifstream petFile("data/pet.txt");
    //    std::string line;
    //    std::getline(petFile, petName);
    //    std::getline(petFile, petType);
    //    std::getline(petFile, line); petIQ = stoi(line);
    //    std::getline(petFile, line); petLove = stoi(line);
    //    std::getline(petFile, line); petEXP = stoi(line);
    //    std::getline(petFile, line); petLevel = stoi(line);
    //    pet = Pet(petName, petType);
    //    pet.setStats(petIQ, petLove, petEXP, petLevel);

    // 5. Open tasks.txt, loop each line and parse Task entries:
    //    std::ifstream taskFile("data/tasks.txt");
    //    while (std::getline(taskFile, line)) {
    //        // expected format: name;type;completedFlag
    //        std::stringstream ss(line);
    //        std::string name, type, flag;
    //        std::getline(ss, name, ';');
    //        std::getline(ss, type, ';');
    //        std::getline(ss, flag, ';');
    //        bool completed = (flag == "1");
    //        tm.addTask(name, type);
    //        if (completed) tm.completeTask(name);
    //    }

    return true;  // Indicate successful load
}

void saveData(const std::string &userName, const Pet &pet, const TaskManager &tm) {
    // 1. Ensure data directory exists; create if missing:
    //    std::filesystem::create_directories("data");

    // 2. Write userName to data/user.txt:
    //    std::ofstream userFile("data/user.txt");
    //    userFile << userName << "\n";

    // 3. Write pet stats to data/pet.txt, each on its own line:
    //    std::ofstream petFile("data/pet.txt");
    //    petFile << pet.getName()  << "\n"
    //            << pet.getType()  << "\n"
    //            << pet.getIQ()    << "\n"
    //            << pet.getLove()  << "\n"
    //            << pet.getEXP()   << "\n"
    //            << pet.getLevel() << "\n";

    // 4. Write tasks to data/tasks.txt, one per line in name;type;flag format:
    //    std::ofstream taskFile("data/tasks.txt");
    //    for (auto &t : tm.getAllTasks()) {
    //        taskFile << t.name << ";" << t.type << ";" << (t.completed ? "1" : "0") << "\n";
    //    }

    // 5. Optional: print confirmation
    //    std::cout << "Progress saved successfully!\n";
}

void resetData() {
    // 1. Delete each data file if it exists:
    //    std::filesystem::remove("data/user.txt");
    //    std::filesystem::remove("data/pet.txt");
    //    std::filesystem::remove("data/tasks.txt");

    // 2. Optionally remove the data directory if empty:
    //    std::filesystem::remove("data");

    // 3. Notify user
    //    std::cout << "All saved data has been reset. Starting fresh next launch.\n";
}

} // namespace DataManager
