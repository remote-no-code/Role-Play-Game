#include "Item.h"

Item::Item(std::string name, ItemType t, std::string desc)
    : itemName(name), type(t), description(desc) {}
