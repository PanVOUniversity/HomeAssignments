#include "Autobot.h"
#include <iostream>

// Constructor
Autobot::Autobot(const std::string& name, int energy_level, const std::string& color, int speed, 
                 const std::string& weapon_type, int weapon_power, 
                 const std::string& commander_name, int mission_count)
    : Transformer(name, energy_level, color, speed, weapon_type, weapon_power), 
      commander_name(commander_name), 
      mission_count(mission_count) {}

// Getter for commander name
std::string Autobot::getCommanderName() const {
    return commander_name;
}

// Setter for commander name
void Autobot::setCommanderName(const std::string& new_commander_name) {
    commander_name = new_commander_name;
}

// Getter for mission count
int Autobot::getMissionCount() const {
    return mission_count;
}

// Setter for mission count
void Autobot::setMissionCount(int new_mission_count) {
    mission_count = new_mission_count;
}

// Display information about the Autobot
void Autobot::displayInfo() const {
    Transformer::displayInfo(); // Display base class details
    std::cout << "Commander Name: " << commander_name << std::endl;
    std::cout << "Mission Count: " << mission_count << std::endl;
}
