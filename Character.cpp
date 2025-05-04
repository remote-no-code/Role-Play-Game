#include <iostream>
#include "Character.h"
#include "Item.h"

Character::Character(std::string n, int h, int str)
    : name(n), health(h), maxHealth(h), armor(0), strength(str),
      level(1), experience(0), actionPoints(5), maxActionPoints(5), critChance(0.1) {}

void Character::addItem(Item* item) {
    inventory.push_back(item);
}

void Character::describe() {
    std::cout << name << " | HP: " << health << "/" << maxHealth
              << ", Armor: " << armor << ", Strength: " << strength
              << ", Level: " << level << ", XP: " << experience
              << ", Action Points: " << actionPoints << "/" << maxActionPoints << std::endl;
}

Character::~Character() {
    for (auto item : inventory)
        delete item;
}

// New: Gain XP and level up
void Character::gainXP(int xp) {
    experience += xp;
    std::cout << name << " gained " << xp << " XP." << std::endl;
    if (experience >= level * 100) { // Example: 100 XP per level
        levelUp();
    }
}

// New: Level up
void Character::levelUp() {
    level++;
    experience = 0;
    maxHealth += 10;
    health = maxHealth;
    strength += 2;
    maxActionPoints += 1;
    std::cout << name << " leveled up to level " << level << "! Stats increased." << std::endl;
}

// New: Check for critical hit
bool Character::checkCrit() {
    double roll = (double)rand() / RAND_MAX;
    return roll < critChance;
}
