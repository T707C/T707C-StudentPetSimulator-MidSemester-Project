#include "Pets.h"
#include "QuadraticHashTable.h"
#include <iostream>
using namespace std;

// Constructor implementation
Pet::Pet(string petName, string petType, int petIQ, int petLove) {
    name = petName;
    type = petType;
    iq = petIQ;
    love = petLove;
}

// Function to rename a pet in the hash table

bool renamePet(string oldName, string newName, QuadraticHashTable &table) {
    Entry petEntry;

    // First, retrieve the current pet data
    if (!table.getPetData(oldName, petEntry)) {
        cout << "Pet '" << oldName << "' does not exist.\n";
        return false;
    }

    // Ensure new name doesn't already exist
    if (table.search(newName) != "Pet not found") {
        cout << "A pet with name '" << newName << "' already exists!\n";
        return false;
    }

    // Remove old pet
    table.removePet(oldName);

    // Reinsert pet with new name clearly using existing data
    table.insert(newName, petEntry.type);

    cout << "Pet renamed successfully from '" << oldName << "' to '" << newName << "'.\n";
    return true;
}

// (Future additions: Pet-related methods, such as leveling logic)
//comment
//MY COMMENT
