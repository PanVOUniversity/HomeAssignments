#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <string>
#include "Weapon.h"

class Transformer {
private:
    std::string name;
    int energy_level;
    std::string color;
    int speed;
    Weapon* weapon;  

public:
    // Constructor
    Transformer(const std::string& name, int energy_level, const std::string& color, int speed,
                const std::string& weapon_type, int weapon_power);

    // Destructor
    ~Transformer();

    // Getters and setters
    std::string getName() const;
    void setName(const std::string& new_name);

    int getEnergyLevel() const;
    void setEnergyLevel(int new_energy_level);

    std::string getColor() const;
    void setColor(const std::string& new_color);

    int getSpeed() const;
    void setSpeed(int new_speed);

    Weapon* getWeapon() const;  // Return the pointer to Weapon

    // Methods
    void accelerate() const;
    void displayInfo() const;
};

#endif // TRANSFORMER_H
