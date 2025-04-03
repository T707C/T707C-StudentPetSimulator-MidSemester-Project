/*


*/


#include "QuadraticHashTable.h"
#include <iostream>
#include <limits>
using namespace std;

QuadraticHashTable::QuadraticHashTable() {
    // struct defaults handle it
}

int QuadraticHashTable::hashFunction(const string &key) {
    int hash = 0;
    for (char ch : key) {
        hash = (hash * 31 + ch) % TABLE_SIZE;
    }
    return hash;
}

// Insert a pet with IQ=1, Love=1
void QuadraticHashTable::insert(const string &petName, const string &petType) {
    int index = hashFunction(petName);
    int i = 0;

    while (table[(index + i*i) % TABLE_SIZE].occupied &&
           table[(index + i*i) % TABLE_SIZE].name != petName &&
           !table[(index + i*i) % TABLE_SIZE].deleted)
    {
        i++;
        if (i == TABLE_SIZE) {
            cout << "Error: Hash Table is full!\n";
            return;
        }
    }

    int finalIndex = (index + i*i) % TABLE_SIZE;
    table[finalIndex].name     = petName;
    table[finalIndex].type     = petType;
    table[finalIndex].iq       = 1;
    table[finalIndex].love     = 1;
    table[finalIndex].occupied = true;
    table[finalIndex].deleted  = false;

    cout << "Pet '" << petName << "' added successfully!\n";
}

// Return info for single pet
string QuadraticHashTable::search(const string &petName) {
    int index = hashFunction(petName);
    int i = 0;

    while (table[(index + i*i) % TABLE_SIZE].occupied) {
        int probeIndex = (index + i*i) % TABLE_SIZE;
        if (table[probeIndex].name == petName && !table[probeIndex].deleted) {
            // Found it
            return "Name: " + table[probeIndex].name +
                   ", Type: " + table[probeIndex].type +
                   ", IQ: " + to_string(table[probeIndex].iq) +
                   ", Love: " + to_string(table[probeIndex].love);
        }
        i++;
        if (i == TABLE_SIZE) break;
    }
    return "Pet not found";
}

void QuadraticHashTable::removePet(const string &petName) {
    int index = hashFunction(petName);
    int i = 0;

    while (table[(index + i*i) % TABLE_SIZE].occupied) {
        int probeIndex = (index + i*i) % TABLE_SIZE;
        if (table[probeIndex].name == petName && !table[probeIndex].deleted) {
            table[probeIndex].deleted = true;
            cout << "Pet '" << petName << "' removed successfully!\n";
            return;
        }
        i++;
        if (i == TABLE_SIZE) break;
    }
    cout << "Pet '" << petName << "' not found.\n";
}

void QuadraticHashTable::showAllPets() {
    bool foundAny = false;
    cout << "\n--- List of All Pets ---\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].occupied && !table[i].deleted) {
            foundAny = true;
            cout << "Name: " << table[i].name
                 << ", Type: " << table[i].type
                 << ", IQ: " << table[i].iq
                 << ", Love: " << table[i].love
                 << endl;
        }
    }
    if (!foundAny) {
        cout << "No pets found.\n";
    }
}

// Return entire Entry data if pet found, otherwise false
bool QuadraticHashTable::getPetData(const string &petName, Entry &outEntry) {
    int index = hashFunction(petName);
    int i = 0;

    while (table[(index + i*i) % TABLE_SIZE].occupied) {
        int probeIndex = (index + i*i) % TABLE_SIZE;
        if (table[probeIndex].name == petName && !table[probeIndex].deleted) {
            outEntry = table[probeIndex];
            return true;
        }
        i++;
        if (i == TABLE_SIZE) break;
    }
    return false;
}

// Re-insert a pet under a new name, keeping type, IQ, love
void QuadraticHashTable::reInsertRenamedPet(const string &oldName, const string &newName) {
    // Step 1: Find old data
    Entry oldData;
    if (!getPetData(oldName, oldData)) {
        cout << "Pet '" << oldName << "' not found.\n";
        return;
    }
    // Step 2: remove old
    removePet(oldName);
    // Step 3: Insert with newName, same type, iq, love
    int index = hashFunction(newName);
    int i = 0;

    while (table[(index + i*i) % TABLE_SIZE].occupied &&
           table[(index + i*i) % TABLE_SIZE].name != newName &&
           !table[(index + i*i) % TABLE_SIZE].deleted)
    {
        i++;
        if (i == TABLE_SIZE) {
            cout << "Error: Hash Table is full!\n";
            return;
        }
    }

    int finalIndex = (index + i*i) % TABLE_SIZE;
    table[finalIndex].name     = newName;
    table[finalIndex].type     = oldData.type;
    table[finalIndex].iq       = oldData.iq;
    table[finalIndex].love     = oldData.love;
    table[finalIndex].occupied = true;
    table[finalIndex].deleted  = false;

    cout << "Renamed pet '" << oldName << "' to '" << newName << "' successfully!\n";
}