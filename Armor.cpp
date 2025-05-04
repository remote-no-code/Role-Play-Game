#include <iostream>
#include "Armor.h"
#include "Character.h"

Armor::Armor(std::string name, int def)
    : Item(name, ItemType::ARMOR, "Protective gear"), isEquipped(false), defense(def), upgradeLevel(0) {}

void Armor::use(Character* user) {
    if (!isEquipped) {
        user->armor += defense;
        isEquipped = true;
        std::cout << "Equipped armor: " << itemName << " (+ " << defense << " armor)" << std::endl;
    }
}

void Armor::upgrade() {
    defense += 2;
    upgradeLevel++;
    std::cout << itemName << " upgraded! Defense now: " << defense << std::endl;
}
