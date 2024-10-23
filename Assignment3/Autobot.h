#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <string>
#include "Weapon.h"  // Assuming Weapon is defined in Weapon.h

class Transformer {
private:
    std::string name;
    int energy_level;
    std::string color;
    int speed;
    Weapon* weapon;  // Pointer to Weapon, using raw pointer for now

public:
    // Constructor
    Transformer(const std::string& name, int energy_level, const std::string& color, int speed, 
                const std::string& weapon_type, int weapon_power);

    // Getters and setters
    std::string getName() const;
    void setName(const std::string& new_name);
    int getEnergyLevel() const;
    void setEnergyLevel(int new_energy_level);
    std::string getColor() const;
    void setColor(const std::string& new_color);
    int getSpeed() const;
    void setSpeed(int new_speed);
    Weapon* getWeapon() const; // Return the pointer to Weapon

    // Methods
    virtual void displayInfo() const;  // Make it virtual for overriding
    void callCritic(const Critic& critic) const; // Assuming Critic is a defined class

    // Destructor
    virtual ~Transformer();
};

#endif // TRANSFORMER_H
