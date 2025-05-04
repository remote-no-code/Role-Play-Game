#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Weapon : public Item {
public:
    int damage;
    bool isEquipped;
    int upgradeLevel;

    Weapon(std::string name, int dmg);
    void use(Character* user) override;
    void upgrade();
};

#endif
