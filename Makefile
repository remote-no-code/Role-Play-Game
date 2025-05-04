CXX = g++
CXXFLAGS = -std=c++17 -Wall

OBJS = main.o Item.o Weapon.o Armor.o Potion.o Character.o Hero.o Monster.o Companion.o Quest.o NPC.o WorldMap.o SaveLoad.o

rpg: $(OBJS)
	$(CXX) -o rpg $(OBJS)

clean:
	rm -f *.o rpg
