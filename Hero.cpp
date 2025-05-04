#include <iostream>
#include "Hero.h"

Hero::Hero(std::string n, int h, int str)
    : Character(n, h, str), companion(nullptr), activeQuest(nullptr) {}

void Hero::attack(Monster* target, bool useSpecial) {
    if (actionPoints <= 0) {
        std::cout << name << " has no action points left!" << std::endl;
        return;
    }

    int dmg = strength - target->armor;
    if (dmg < 0) dmg = 0;

    // Special attack costs 2 AP but adds bonus damage
    if (useSpecial && actionPoints >= 2) {
        dmg += 5;
        actionPoints -= 2;
        std::cout << name << " uses a special attack!" << std::endl;
    } else {
        actionPoints -= 1;
    }

    // Check for critical hit
    if (checkCrit()) {
        dmg *= 2;
        std::cout << "Critical hit!" << std::endl;
    }

    target->health -= dmg;
    std::cout << name << " attacks " << target->name << " for " << dmg << " damage!" << std::endl;

    if (target->health <= 0 && target->isAlive) {
        target->isAlive = false;
        std::cout << target->name << " was slain!" << std::endl;
        gainXP(50); // Example: gain 50 XP per kill

        if (activeQuest && activeQuest->requiredMonster == target->name &&
            activeQuest->status == QuestStatus::IN_PROGRESS) {
            activeQuest->status = QuestStatus::COMPLETED;
            std::cout << "Quest '" << activeQuest->name << "' completed!" << std::endl;
        }
    }
}

void Hero::assignCompanion(Companion* c) {
    companion = c;
    std::cout << c->name << " has joined your party!" << std::endl;
}

void Hero::acceptQuest(Quest* q) {
    activeQuest = q;
    q->status = QuestStatus::IN_PROGRESS;
    std::cout << "Accepted quest: " << q->name << std::endl;
}
