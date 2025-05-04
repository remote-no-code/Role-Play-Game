#include <iostream>
#include "NPC.h"

NPC::NPC(std::string n, Quest* q)
    : Character(n, 100, 0), quest(q) {}

void NPC::talk(Hero* hero) {
    std::cout << name << ": 'Greetings, hero!'\n";
    if (quest && quest->status == QuestStatus::NOT_STARTED) {
        std::cout << "1. Accept Quest\n2. Decline\nChoice: ";
        int choice;
        std::cin >> choice;
        if (choice == 1) hero->acceptQuest(quest);
        else std::cout << name << ": 'Maybe next time.'\n";
    } else {
        std::cout << name << ": 'Good luck on your journey.'\n";
    }
}
