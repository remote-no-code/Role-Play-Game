#ifndef WORLDMAP_H
#define WORLDMAP_H

#include <string>
#include <vector>

class WorldMap {
public:
    std::vector<std::string> locations;
    int currentLocation;

    WorldMap();
    void showLocations();
    void moveTo(int index);
};

#endif
