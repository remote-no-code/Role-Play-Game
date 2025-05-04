#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"

class Armor : public Item {
public:
    bool isEquipped;
    int defense;
    int upgradeLevel;

    Armor(std::string name, int def);
    void use(Character* user) override;
    void upgrade();
};

#endif
