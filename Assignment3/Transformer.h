#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <string>
#include <memory>  // For std::unique_ptr
#include "Weapon.h"

class Transformer {
public:
    Transformer(const std::string& name, int energy_level, const std::string& color,
                int speed, const std::string& weapon_type, int weapon_power);
    
    std::string getName() const;
    void setName(const std::string& new_name);
    int getEnergyLevel() const;
    void setEnergyLevel(int new_energy_level);
    std::string getColor() const;
    void setColor(const std::string& new_color);
    int getSpeed() const;
    void setSpeed(int new_speed);
    std::unique_ptr<Weapon> getWeapon() const;

    virtual void displayInfo() const;  // Declaration
    virtual ~Transformer();  // Virtual destructor

private:
    std::string name;
    int energy_level;
    std::string color;
    int speed;
    std::unique_ptr<Weapon> weapon;
};

#endif // TRANSFORMER_H
