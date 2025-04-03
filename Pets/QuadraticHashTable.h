#ifndef QUADRATIC_HASH_TABLE_H
#define QUADRATIC_HASH_TABLE_H

#include <string>
using namespace std;

const int TABLE_SIZE = 101;

struct Entry {
    string name;   // Pet Name
    string type;   // Pet Type
    int iq;        // default 1
    int love;      // default 1
    bool occupied;
    bool deleted;

    Entry() : name(""), type(""), iq(1), love(1), occupied(false), deleted(false) {}
};

class QuadraticHashTable {
private:
    Entry table[TABLE_SIZE];
    int hashFunction(const string &key);

public:
    QuadraticHashTable();

    // Insert (Name + Type Only)
    void insert(const string &petName, const string &petType);

    // Search: returns "Pet not found" or "Name: X, Type: Y, IQ: Z, Love: W"
    string search(const string &petName);

    // Remove pet by name
    void removePet(const string &petName);

    // Show all pets
    void showAllPets();

    // (NEW) Get the entire Entry data for a pet (returns true if found)
    bool getPetData(const string &petName, Entry &outEntry);

    // (NEW) Re-insert an existing Entry with a new name
    void reInsertRenamedPet(const string &oldName, const string &newName);
};

#endif
