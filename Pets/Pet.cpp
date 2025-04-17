// ======== Pet Class Implementation ========
// Implements the methods declared in Pet.h, providing logic for:
//  - Constructing a new Pet with default stats
//  - Awarding experience (EXP) for completed tasks
//  - Checking and performing level-ups when EXP thresholds are reached
//  - Accessing Pet properties via getters

#include "Pets.h"  // Class declaration
#include <iostream>  // For console output

// Constructor: initialize name, type, and default stats
Pet::Pet(const string &name, const string &type)
    : name(name), type(type), iq(1), love(1), exp(0), level(1) {
    // Announce creation
    cout << "Your new pet '" << this->name << "' (" << this->type << ") has been created!\n";
}

// gainEXP: add experience points to the pet
void Pet::gainEXP(int amount) {
    exp += amount;
    cout << "[Pet] " << name << " gained " << amount << " EXP (total EXP: " << exp << ")\n";
}

// shouldLevelUp: returns true if exp >= threshold (level * 100)
bool Pet::shouldLevelUp() const {
    int threshold = level * 100;
    return exp >= threshold;
}

// levelUp: increases level, resets exp, and boosts stats
void Pet::levelUp() {
    int threshold = level * 100;
    if (exp < threshold) {
        cout << "[Pet] Not enough EXP to level up. Need " << (threshold - exp) << " more.\n";
        return;
    }

    exp -= threshold;        // subtract used EXP; keep overflow
    level += 1;             // increment level
    iq += 1;                // boost IQ by 1 per level
    love += 1;              // boost Love by 1 per level

    cout << "[Pet] " << name << " leveled up to level " << level << "!";
    cout << " (IQ=" << iq << ", Love=" << love << ")\n";
}

// Getters for each property
const string& Pet::getName() const {
    return name;
}

const string& Pet::getType() const {
    return type;
}

int Pet::getIQ() const {
    return iq;
}

int Pet::getLove() const {
    return love;
}

int Pet::getEXP() const {
    return exp;
}

int Pet::getLevel() const {
    return level;
}
