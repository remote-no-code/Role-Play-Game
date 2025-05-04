#ifndef HERO_H
#define HERO_H

#include "Character.h"
#include "Companion.h"
#include "Quest.h"
#include "Monster.h"

class Hero : public Character {
public:
    Companion* companion;
    Quest* activeQuest;

    Hero(std::string n, int h, int str);
    void attack(Monster* target, bool useSpecial);
    void assignCompanion(Companion* c);
    void acceptQuest(Quest* q);
};

#endif
