#ifndef PETS_H
#define PETS_H

#include <string>
using namespace std;

// Pet struct clearly defines the data stored for each pet
struct Pet {
    string name;   
    string type;   
    int iq;
    int love;

    // Constructor for quick initialization
    Pet(string petName = "", string petType = "", int petIQ = 1, int petLove = 1);
};

    // Rename Pet function declared here
bool renamePet(string oldName, string newName, class QuadraticHashTable &table);


#endif
