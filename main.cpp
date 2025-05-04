#include <iostream>
#include "Hero.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"
#include "Monster.h"
#include "Companion.h"
#include "Quest.h"
#include "NPC.h"
#include "WorldMap.h"
#include "SaveLoad.h"

int main() {
    Hero player("Knight", 120, 18);
    Companion ally("Archer", 80, 12);
    player.assignCompanion(&ally);

    Weapon* sword = new Weapon("Iron Sword", 10);
    Armor* shield = new Armor("Steel Shield", 8);
    Potion* potion = new Potion("Healing Potion", 30);

    player.addItem(sword);
    player.addItem(shield);
    player.addItem(potion);

    sword->use(&player);
    shield->use(&player);
    sword->upgrade();
    shield->upgrade();

    Quest goblinQuest("Goblin Slayer", "Eliminate the Goblin menace", "Goblin");
    NPC elder("Village Elder", &goblinQuest);

    WorldMap world;
    Monster goblin("Goblin", 50, 10, true);

    SaveLoad::loadGame(player, goblin);

    std::cout << "\n--- Talking to Elder ---\n";
    elder.talk(&player);

    while (true) {
        std::cout << "\n\n1. Show Map\n2. Move\n3. Fight Goblin\n4. Save Game\n5. Exit\nChoice: ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            world.showLocations();
        } else if (choice == 2) {
            world.showLocations();
            std::cout << "Enter location number: ";
            int loc;
            std::cin >> loc;
            world.moveTo(loc);
        } else if (choice == 3) {
            while (goblin.isAlive && player.health > 0) {
                player.describe();
                goblin.describe();
                std::cout << "\n1. Normal Attack\n2. Special Attack\n3. Use Potion\nChoice: ";
                int action;
                std::cin >> action;

                if (action == 1) {
                    player.attack(&goblin, false);
                    if (player.companion) player.companion->assist(&goblin);
                } else if (action == 2) {
                    player.attack(&goblin, true);
                    if (player.companion) player.companion->assist(&goblin);
                } else if (action == 3) {
                    potion->use(&player);
                }

                if (goblin.isAlive) {
                    goblin.attack(&player);
                }

                if (player.health <= 0) {
                    std::cout << "You have been defeated...\n";
                    return 0;
                }
            }

            if (!goblin.isAlive) {
                goblin.respawn();
            }
        } else if (choice == 4) {
            SaveLoad::saveGame(player, goblin);
        } else {
            break;
        }
    }

    return 0;
}
