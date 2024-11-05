#ifndef AUTOBOT_H
#define AUTOBOT_H

<<<<<<< HEAD
Autobot::Autobot(const std::string& name, int energy_level, const std::string& color, int speed, 
                 const std::string& weapon_type, int weapon_power,
                 const std::string& commander_name, int mission_count)
    : Transformer(name, energy_level, color, speed, weapon_type, weapon_power),
      commander_name(commander_name), mission_count(mission_count) {}

void Autobot::displayInfo() const {
    Transformer::displayInfo();  // Call base class implementation
    std::cout << "Commander: " << commander_name << ", Mission Count: " << mission_count << std::endl;
}
=======
#include "Transformer.h"
#include <string>

class Autobot : public Transformer {
private:
    std::string commander_name;
    int mission_count;

public:
    // Constructor
    Autobot(const std::string& name, int energy_level, const std::string& color, int speed, 
            const std::string& weapon_type, int weapon_power, 
            const std::string& commander_name, int mission_count);

    // Getters and setters for commander name and mission count
    std::string getCommanderName() const;
    void setCommanderName(const std::string& new_commander_name);

    int getMissionCount() const;
    void setMissionCount(int new_mission_count);

    // Overriding displayInfo 
    void displayInfo() const override;
};

#endif 
>>>>>>> d1879e35af04202e292847f7100114ca99638a73
