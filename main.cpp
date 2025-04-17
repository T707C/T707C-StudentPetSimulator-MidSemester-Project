// Semester Project: ...
// Names: Taylor Carver W10188648, ...
// Date: ...


// ======== Task Pet Simulator ========
// This is the program entry point and menu loop for the Task Pet Simulator.
// Right now, we focus solely on the Task Management system:
//  - It initializes a TaskManager instance
//  - Presents a menu for adding, viewing, completing, and deleting tasks
//  - Exits cleanly when the user chooses to quit
// Later, we will integrate pet creation and stat-tracking around these tasks.


// ------------------------------------------------------------------------------------------//



#include <iostream>         // For input/output streams (cin, cout)
#include <limits>           // For streamsize and numeric_limits
#include "Tasks/TaskManager.h"  // TaskManager handles Task CRUD operations

using namespace std;

int main() {
    // Create the TaskManager which stores and operates on Task objects
    TaskManager taskManager;

    while (true) {
        // Display the main menu for task operations
        cout << "\n==== TASK PET SIMULATOR - TASK MENU ====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Complete Task\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Select an option (1-5): ";

        int choice;
        cin >> choice;
        // Clear leftover newline from the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string name, type;
        switch (choice) {
            case 1:
                // Add a new task: prompt for name and type
                cout << "Enter task name: ";
                getline(cin, name);
                cout << "Enter task type (e.g., academic, personal): ";
                getline(cin, type);
                taskManager.addTask(name, type);
                break;

            case 2:
                // View all current tasks with their status
                taskManager.viewTasks();
                break;

            case 3:
                // Mark a specific task as complete
                cout << "Enter task name to complete: ";
                getline(cin, name);
                taskManager.completeTask(name);
                break;

            case 4:
                // Delete a specific task from the list
                cout << "Enter task name to delete: ";
                getline(cin, name);
                taskManager.deleteTask(name);
                break;

            case 5:
                // Exit the application
                cout << "Exiting... Goodbye!\n";
                return 0;

            default:
                // Handle invalid menu choices
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0; // Unreachable but provided for clarity
}
    