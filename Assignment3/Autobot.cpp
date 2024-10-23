#include "Autobot.h"
#include <iostream>

Autobot::Autobot(const std::string& name, int energy_level, const std::string& color, int speed, const std::string& weapon_type, int weapon_power,
                 const std::string& commander_name, int mission_count)
    : Transformer(name, energy_level, color, speed, weapon_type, weapon_power),
      commander_name(commander_name), mission_count(mission_count) {}

std::string Autobot::getCommanderName() const {
    return commander_name;
}

void Autobot::setCommanderName(const std::string& new_commander_name) {
    commander_name = new_commander_name;
}

int Autobot::getMissionCount() const {
    return mission_count;
}

void Autobot::setMissionCount(int new_mission_count) {
    mission_count = new_mission_count;
}

void Autobot::displayInfo() const {
    Transformer::displayInfo();
    std::cout << "Commander: " << commander_name << ", Mission Count: " << mission_count << std::endl;
}
