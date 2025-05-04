#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include <cstdlib>  // For rand
class Item;

class Character {
public:
    std::string name;
    int health;
    int maxHealth;
    int armor;
    int strength;
    int level;
    int experience;
    int actionPoints;
    int maxActionPoints;
    double critChance; // Critical hit chance (e.g., 0.1 = 10%)
    std::vector<Item*> inventory;

    Character(std::string n, int h, int str);
    void addItem(Item* item);
    virtual void describe();
    virtual ~Character();

    // New functions:
    void gainXP(int xp);
    void levelUp();
    bool checkCrit();
};

#endif
