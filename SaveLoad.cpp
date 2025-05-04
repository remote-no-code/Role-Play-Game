#include <iostream>
#include <fstream>
#include "SaveLoad.h"

void SaveLoad::saveGame(const Hero& hero, const Monster& monster) {
    std::ofstream file("savegame.txt");
    if (file) {
        file << hero.level << " " << hero.experience << " " << hero.health << " " << monster.health << " " << monster.isAlive << "\n";
        file.close();
        std::cout << "Game saved.\n";
    } else {
        std::cout << "Failed to save game.\n";
    }
}

void SaveLoad::loadGame(Hero& hero, Monster& monster) {
    std::ifstream file("savegame.txt");
    if (file) {
        int heroLevel, heroXP, heroHealth, monsterHealth, monsterAlive;
        file >> heroLevel >> heroXP >> heroHealth >> monsterHealth >> monsterAlive;
        hero.level = heroLevel;
        hero.experience = heroXP;
        hero.health = heroHealth;
        monster.health = monsterHealth;
        monster.isAlive = monsterAlive;
        file.close();
        std::cout << "Game loaded.\n";
    } else {
        std::cout << "No save file found.\n";
    }
}
