#ifndef SAVELOAD_H
#define SAVELOAD_H

#include "Hero.h"
#include "Monster.h"

class SaveLoad {
public:
    static void saveGame(const Hero& hero, const Monster& monster);
    static void loadGame(Hero& hero, Monster& monster);
};

#endif
