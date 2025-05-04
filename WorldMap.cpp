#include <iostream>
#include "WorldMap.h"

WorldMap::WorldMap() : currentLocation(0) {
    locations.push_back("Village");
    locations.push_back("Forest");
    locations.push_back("Cave");
}

void WorldMap::showLocations() {
    std::cout << "Available locations:\n";
    for (int i = 0; i < locations.size(); i++) {
        std::cout << i << ". " << locations[i] << (i == currentLocation ? " (current)" : "") << "\n";
    }
}

void WorldMap::moveTo(int index) {
    if (index >= 0 && index < locations.size()) {
        currentLocation = index;
        std::cout << "Moved to: " << locations[currentLocation] << "\n";
    } else {
        std::cout << "Invalid location choice.\n";
    }
}
