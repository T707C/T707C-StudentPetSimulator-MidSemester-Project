// Semester Project: ...
// Names: Taylor Carver W10188648, ...
// Date: ...


// ======== Task Pet Simulator ========
// Entry point and menu loop for the Task Pet Simulator.
// - Prompts the user to choose and name a single pet on first launch.
// - Integrates the TaskManager for task CRUD operations.
// - Rewards the pet with EXP when tasks are completed, allowing leveling.
// - Displays pet stats via a menu option.

#include <iostream>
#include "Data/DataManager.h"
#include <string>
#include <limits>
#include <cctype>
#include "Pets/Pets.h"            // Pet class: name, type, stats, leveling
#include "Tasks/TaskManager.h"  // TaskManager: handles Task list operations

using namespace std;

// Trim leading/trailing whitespace from a string
static void trimString(string &str) {
    while (!str.empty() && isspace(str.back())) str.pop_back();
    while (!str.empty() && isspace(str.front())) str.erase(0, 1);
}

int main() {
    // ----- Attempt To Load A Previous Session ----- //
    if (!DataManager::loadData(userName, pet, taskManager)) {
        // first-run: prompt for name & pet setup
    }

    // ---- USER SETUP ---- //
        // TODO: Declare a string to hold the user's name
        string userName;

        // TODO: Prompt the user: "Enter your name: " and read into userName
        // TODO: Trim whitespace
    
        // Example greeting: "Hello, <userName>!"


    // --- PET SETUP --- //
    cout << "Welcome to Task Pet Simulator!" << endl;
    cout << "Choose your companion (dog/cat): ";
    string petType;
    getline(cin, petType);
    trimString(petType);

    cout << "Name your pet: ";
    string petName;
    getline(cin, petName);
    trimString(petName);

    // Create pet with default stats (IQ=1, Love=1, EXP=0, Level=1)
    Pet pet(petName, petType);

    // Initialize Task Manager
    TaskManager taskManager;

    while (true) {
        // --- MAIN MENU ---
        cout << "\n==== TASK PET SIMULATOR ====" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Complete Task" << endl;
        cout << "4. Delete Task" << endl;
        cout << "5. View Pet Info" << endl;
        cout << "6. Exit" << endl;
        // Add Option 7 (Rest Application)
        cout << "Select an option (1-6): ";

        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Flush newline

        string name, type;
        switch (choice) {
            case 1:
                // Add Task
                cout << "Enter task name: ";
                getline(cin, name);
                trimString(name);
                cout << "Enter task type: ";
                getline(cin, type);
                trimString(type);
                taskManager.addTask(name, type);
                break;

            case 2:
                // View Tasks
                taskManager.viewTasks();
                break;

            case 3:
                // Complete Task and reward pet
                cout << "Enter task name to complete: ";
                getline(cin, name);
                trimString(name);
                if (taskManager.completeTask(name)) {
                    pet.gainEXP(10);  // reward 10 EXP per task
                    if (pet.shouldLevelUp()) {
                        pet.levelUp();
                    }
                }
                break;

            case 4:
                // Delete Task
                cout << "Enter task name to delete: ";
                getline(cin, name);
                trimString(name);
                taskManager.deleteTask(name);
                break;

            case 5:
                // Display Pet Info
                cout << "\n-- Your Pet Info --" << endl;
                cout << "Name : " << pet.getName()  << endl;
                cout << "Type : " << pet.getType()  << endl;
                cout << "IQ   : " << pet.getIQ()    << endl;
                cout << "Love : " << pet.getLove()  << endl;
                cout << "EXP  : " << pet.getEXP()    << endl;
                cout << "Level: " << pet.getLevel() << endl;
                break;

            /* ------------------------- EXIT ------------------------ */
            case 6: {
                char save;
                cout << "Save progress before exit? (Y/N): ";
                cin >> save;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                save = static_cast<char>(toupper(save));

                if (save == 'Y') {
                    DataManager::saveData(userName, pet, taskManager);
                    cout << "Progress saved.\n";
                }
                cout << "Exiting… Goodbye!\n";
                return 0;
            }
            /* ------------------------ RESET ------------------------ */
            case 7: {
                char confirm;
                cout << "⚠  This will ERASE all saved data.  Are you sure? (Y/N): ";
                cin >> confirm;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                confirm = static_cast<char>(toupper(confirm));

                if (confirm == 'Y') {
                    DataManager::resetData();
                    cout << "All data cleared.  Restart the program to begin anew.\n";
                    return 0;      // terminate after reset
                }
                break;             // user changed their mind
            }
            
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
