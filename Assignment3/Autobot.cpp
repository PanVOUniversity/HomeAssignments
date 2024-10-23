#include "Autobot.h"
#include <iostream>

Autobot::Autobot(const std::string& name, int energy_level, const std::string& color, int speed, 
                 const std::string& weapon_type, int weapon_power,
                 const std::string& commander_name, int mission_count)
    : Transformer(name, energy_level, color, speed, weapon_type, weapon_power),
      commander_name(commander_name), mission_count(mission_count) {}

void Autobot::displayInfo() const {
    Transformer::displayInfo();  // Call base class implementation
    std::cout << "Commander: " << commander_name << ", Mission Count: " << mission_count << std::endl;
}
