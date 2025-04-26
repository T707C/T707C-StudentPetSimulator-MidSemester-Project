// ======== Pet Class Definition ========
// This header defines the Pet class, representing the user's single
// companion. Each Pet has a name and type (e.g., dog, cat), along with
// stats: IQ, Love, EXP, and Level. Methods allow rewarding EXP and
// leveling up when thresholds are met.

#ifndef PET_H
#define PET_H

#include <string>
using namespace std;

class Pet {
private:
    string name;    // Pet's given name
    string type;    // Pet species/category (dog, cat, etc.)
    int iq;         // Intelligence stat (default 1)
    int love;       // Affection stat (default 1)
    int exp;        // Experience points accumulated
    int level;      // Current level (default 1)

public:
    // Constructor: initialize a pet with given name & type;
    // stats default to iq=1, love=1, exp=0, level=1
    Pet(const string &name, const string &type);

    // Reward the pet with EXP; increases exp by amount
    void gainEXP(int amount);

    // Returns true if exp meets threshold to level up
    bool shouldLevelUp() const;

    // Level up: increment level, reset exp, and boost stats
    void levelUp();

    // Simple getters
    const string& getName() const;
    const string& getType() const;
    int getIQ() const;
    int getLove() const;
    int getEXP() const;
    int getLevel() const;

    // Setters
    void setIQ(int iq) { this->iq = iq; }
    void setLove(int love) { this->love = love; }
    void setEXP(int exp) { this->exp = exp; }
    void setLevel(int level) { this->level = level; }
};

#endif

