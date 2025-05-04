#ifndef QUEST_H
#define QUEST_H

#include <string>

enum class QuestStatus { NOT_STARTED, IN_PROGRESS, COMPLETED };

class Quest {
public:
    std::string name;
    std::string description;
    QuestStatus status;
    std::string requiredMonster;

    Quest(std::string n, std::string d, std::string monster);
    void describe();
};

#endif
