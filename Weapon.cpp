#include <iostream>
#include "Weapon.h"
#include "Character.h"

Weapon::Weapon(std::string name, int dmg)
    : Item(name, ItemType::WEAPON, "A weapon"), damage(dmg), isEquipped(false), upgradeLevel(0) {}

void Weapon::use(Character* user) {
    if (!isEquipped) {
        user->strength += damage;
        isEquipped = true;
        std::cout << "Equipped weapon: " << itemName << " (+ " << damage << " attack)" << std::endl;
    }
}

void Weapon::upgrade() {
    damage += 3;
    upgradeLevel++;
    std::cout << itemName << " upgraded! Damage now: " << damage << std::endl;
}
