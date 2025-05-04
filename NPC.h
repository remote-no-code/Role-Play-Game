#ifndef NPC_H
#define NPC_H

#include "Character.h"
#include "Quest.h"
#include "Hero.h"

class NPC : public Character {
public:
    Quest* quest;

    NPC(std::string n, Quest* q);
    void talk(Hero* hero);
};

#endif
