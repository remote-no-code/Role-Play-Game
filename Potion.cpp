#include <iostream>
#include "Potion.h"
#include "Character.h"

Potion::Potion(std::string name, int heal)
    : Item(name, ItemType::POTION, "Restores health"), healing(heal) {}

void Potion::use(Character* user) {
    user->health += healing;
    if (user->health > user->maxHealth)
        user->health = user->maxHealth;
    std::cout << "Used " << itemName << ", healed " << healing << " HP." << std::endl;
}
