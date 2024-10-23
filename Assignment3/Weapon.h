#ifndef AUTOBOT_H
#define AUTOBOT_H

#include "Transformer.h"

class Autobot : public Transformer {
 private:
    std::string commander_name;
    int mission_count;

 public:
    Autobot(const std::string& name, int energy_level, const std::string& color, int speed, const std::string& weapon_type, int weapon_power,
            const std::string& commander_name, int mission_count);
    
    std::string getCommanderName() const;
    void setCommanderName(const std::string& new_commander_name);
    int getMissionCount() const;
    void setMissionCount(int new_mission_count);
    
    void displayInfo() const override;
};

#endif // AUTOBOT_H
