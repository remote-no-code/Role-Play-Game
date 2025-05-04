#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"

class Monster : public Character {
public:
    bool isAlive;
    bool aggressive; // New: AI mode

    Monster(std::string n, int h, int str, bool isAggressive);
    void attack(Character* target);
    void respawn();
};

#endif
