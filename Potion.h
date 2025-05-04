#ifndef POTION_H
#define POTION_H

#include "Item.h"

class Potion : public Item {
public:
    int healing;

    Potion(std::string name, int heal);
    void use(Character* user) override;
};

#endif
