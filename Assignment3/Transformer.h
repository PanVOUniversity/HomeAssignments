#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <string>
#include <memory>
#include "Weapon.h"

class Transformer {
private:
    std::string name;
    int energy_level;
    std::string color;
    int speed;
    std::unique_ptr<Weapon> weapon;  // Use unique_ptr for automatic memory management

public:
    // Constructor
    Transformer(const std::string& name, int energy_level, const std::string& color, int speed,
                const std::string& weapon_type, int weapon_power);

    // Destructor
    virtual ~Transformer();

    // Getters and setters
    std::string getName() const;
    void setName(const std::string& new_name);

    int getEnergyLevel() const;
    void setEnergyLevel(int new_energy_level);

    std::string getColor() const;
    void setColor(const std::string& new_color);

    int getSpeed() const;
    void setSpeed(int new_speed);

    Weapon* getWeapon() const;  // Return raw pointer for simplicity

    // Methods
    virtual void displayInfo() const;
};

#endif // TRANSFORMER_H
