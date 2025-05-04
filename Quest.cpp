#include <iostream>
#include "Quest.h"

Quest::Quest(std::string n, std::string d, std::string monster)
    : name(n), description(d), status(QuestStatus::NOT_STARTED), requiredMonster(monster) {}

void Quest::describe() {
    std::cout << "Quest: " << name << " — " << description << std::endl;
}
