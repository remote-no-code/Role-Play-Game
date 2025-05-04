#include <iostream>
#include "Monster.h"

Monster::Monster(std::string n, int h, int str, bool isAggressive)
    : Character(n, h, str), isAlive(true), aggressive(isAggressive) {}

void Monster::attack(Character* target) {
    if (!isAlive || actionPoints <= 0) return;

    int dmg = strength - target->armor;
    if (dmg < 0) dmg = 0;

    // Monster AI: if aggressive, more likely to hit hard
    if (aggressive && actionPoints >= 2) {
        dmg += 5;
        actionPoints -= 2;
        std::cout << name << " launches a fierce attack!" << std::endl;
    } else {
        actionPoints -= 1;
    }

    // Critical chance for monsters too!
    if (checkCrit()) {
        dmg *= 2;
        std::cout << "Monster critical hit!" << std::endl;
    }

    target->health -= dmg;
    std::cout << name << " attacks " << target->name << " for " << dmg << " damage!" << std::endl;
}

void Monster::respawn() {
    health = maxHealth;
    isAlive = true;
    actionPoints = maxActionPoints;
    std::cout << name << " has respawned!" << std::endl;
}
