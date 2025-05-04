#ifndef ITEM_H
#define ITEM_H

#include <string>
class Character;

enum class ItemType { WEAPON, ARMOR, POTION };

class Item {
public:
    std::string itemName;
    ItemType type;
    std::string description;

    Item(std::string name, ItemType t, std::string desc = "");
    virtual void use(Character* user) = 0;
    virtual ~Item() = default;
};

#endif
