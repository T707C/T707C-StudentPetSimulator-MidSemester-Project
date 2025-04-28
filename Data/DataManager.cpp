// ======== Data Management Module Implementation ========
// Implements the DataManager functions declared in DataManager.h
// This file contains stubs with detailed pseudocode comments indicating
// how to read/write the user, pet, and task data to local files.

#include "DataManager.h"
#include <fstream>      
#include <filesystem>   
#include <sstream>      
#include <iostream> 
#include <algorithm> 

namespace fs = std::filesystem;

namespace DataManager {

static void trimString(std::string &str) {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), str.end());
}

bool loadData(std::string &userName, Pet &pet, TaskManager &tm) {
    // 1. Ensure data directory exists
    if (!fs::exists("data")) 
        return false;

    // 2. Check existence of each required file
    if (!fs::exists("data/user.txt") || !fs::exists("data/pet.txt") || !fs::exists("data/tasks.txt"))
        return false;  // First-run: no saved data

    // 3. Open user.txt and read the single line into userName
    std::ifstream userFile("data/user.txt");
    if (!userFile) return false;
    std::getline(userFile, userName);
    trimString(userName);

    // 4. Open pet.txt and read fields line by line:
    std::ifstream petFile("data/pet.txt");
    if (!petFile) return false;

    std::string line;
    int iq, love, exp, level;
    
    std::getline(petFile, line);  // Name
    string petName = line;
    std::getline(petFile, line);  // Type
    string petType = line;
    
    std::getline(petFile, line); iq = stoi(line);
    std::getline(petFile, line); love = stoi(line);
    std::getline(petFile, line); exp = stoi(line);
    std::getline(petFile, line); level = stoi(line);
    
    pet = Pet(petName, petType);
    pet.setIQ(iq);
    pet.setLove(love);
    pet.setEXP(exp);
    pet.setLevel(level);


    // 5. Open tasks.txt, loop each line and parse Task entries:
    std::ifstream taskFile("data/tasks.txt");
    if (!taskFile) return false;
    
    while (std::getline(taskFile, line)) {
        stringstream ss(line);
        string name, type, flag;
        getline(ss, name, ';');
        getline(ss, type, ';');
        getline(ss, flag, ';');
        
        tm.addTask(name, type);
        if (flag == "1") tm.completeTask(name);
    }


    return true;  // Indicate successful load
}

void saveData(const std::string &userName, const Pet &pet, const TaskManager &tm) {
    fs::create_directories("data");

    // 2. Write userName to data/user.txt:
    std::ofstream userFile("data/user.txt");
    userFile << userName << "\n";

    // 3. Write pet stats to data/pet.txt, each on its own line:
    std::ofstream petFile("data/pet.txt");
    petFile << pet.getName()  << "\n"
                << pet.getType()  << "\n"
                << pet.getIQ()    << "\n"
                << pet.getLove()  << "\n"
                << pet.getEXP()   << "\n"
                << pet.getLevel() << "\n";

    // 4. Write tasks to data/tasks.txt, one per line in name;type;flag format:
    std::ofstream taskFile("data/tasks.txt");
    for (const auto &t : tm.getTasks()) {
        taskFile << t.name << ";" << t.type << ";" << (t.completed ? "1" : "0") << "\n";

    // 5. Optional: print confirmation
    std::cout << "Progress saved successfully!\n"; }
}

void resetData() {
    // 1. Delete each data file if it exists:
    fs::remove("data/user.txt");
    fs::remove("data/pet.txt");
    fs::remove("data/tasks.txt");

    // 2. Optionally remove the data directory if empty:
    std::error_code ec;
    fs::remove("data", ec);

    // 3. Notify user
    std::cout << "All saved data has been reset. Starting fresh next launch.\n";
}

} // namespace DataManager
