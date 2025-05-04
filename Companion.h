#ifndef COMPANION_H
#define COMPANION_H

#include "Character.h"
#include "Monster.h"

class Companion : public Character {
public:
    Companion(std::string n, int h, int str);
    void assist(Monster* target);
};

#endif
