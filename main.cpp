// Semester Project: ...
// Names: Taylor Carver W10188648, ...
// Date: ...


/* === Menu System (Teammate: *insert name*) ===
    
    This file contains the main program loop for interacting with
    the hash table.
    
    You'll build a simple menu that allows the user to: 
    1. Add a new pet
    2.View a pet's information
    3. Delete a pet
    4. Exit the program
    
    This will connect with the QuadraticHashTable class already build.
    The job here is to fill in the switch-case logic using table.insert(),
    table.search(), and table.remove().
    
    */


    #include <iostream>
    #include <string>
    #include <algorithm>
    #include <cctype>
    #include <limits>
    #include "QuadraticHashTable.h"
    #include "Pets.h"
    using namespace std;
    
    // We'll declare the rename function from PetUpdate.cpp
    void updatePetName(QuadraticHashTable &table);
    
    static void trimString(string &str) {
        while (!str.empty() && isspace(str.back())) str.pop_back();
        while (!str.empty() && isspace(str.front())) str.erase(0, 1);
    }
    
    int main() {
        QuadraticHashTable table;
        while (true) {
            cout << "\n~~~~ Pet Simulator ~~~~\n"
                 << "1. Add a Pet\n"
                 << "2. View a Pet\n"
                 << "3. Delete a Pet\n"
                 << "4. Rename a Pet\n"
                 << "5. Show All Pets\n"
                 << "6. Exit\n"
                 << "Select an option (1-6): ";
    
            int choice;
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush leftover \n
    
            if (choice == 1) {
                // Add
                string petName, petType;
                cout << "Enter pet name: ";
                getline(cin, petName);
                trimString(petName);
    
                cout << "Enter pet type: ";
                getline(cin, petType);
                trimString(petType);
    
                table.insert(petName, petType);
    
            } else if (choice == 2) {
                // View one pet
                string petName;
                cout << "Enter pet name to search for: ";
                getline(cin, petName);
                trimString(petName);
    
                string result = table.search(petName);
                cout << "Pet Info: " << result << endl;
    
            } else if (choice == 3) {
                // Delete
                string petName;
                cout << "Enter pet name to delete: ";
                getline(cin, petName);
                trimString(petName);
    
                table.removePet(petName);
    
            } else if (choice == 4) {
                // Rename a Pet
                string oldName, newName;
                cout << "Enter the old pet name: ";
                getline(cin, oldName);

                cout << "Enter the new pet name: ";
                getline(cin, newName);

                if (!renamePet(oldName, newName, table)) {
                    cout << "Failed to rename pet. Check if pet's name is correct.\n";
                } else {
                    cout << "Pet renamed successfully from '" << oldName << "' to '" << newName << "'.\n";
                }
                    break;
                
            
    
            } else if (choice == 5) {
                table.showAllPets();
    
            } else if (choice == 6) {
                cout << "Exiting the program. Goodbye!\n";
                return 0;
    
            } else {
                cout << "Invalid choice. Try again.\n";
            }
        }
        return 0;
    };
    