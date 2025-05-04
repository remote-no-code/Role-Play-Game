#include <iostream>
#include "Companion.h"

Companion::Companion(std::string n, int h, int str)
    : Character(n, h, str) {}

void Companion::assist(Monster* target) {
    if (target->isAlive && actionPoints > 0) {
        int dmg = strength - target->armor;
        if (dmg < 0) dmg = 0;

        // Critical hit chance
        if (checkCrit()) {
            dmg *= 2;
            std::cout << "Companion critical hit!" << std::endl;
        }

        target->health -= dmg;
        actionPoints -= 1;
        std::cout << name << " assists and hits " << target->name << " for " << dmg << " damage!" << std::endl;

        if (target->health <= 0 && target->isAlive) {
            target->isAlive = false;
            std::cout << target->name << " was defeated by your companion!" << std::endl;
        }
    }
}
