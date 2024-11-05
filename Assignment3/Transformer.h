#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <string>
<<<<<<< HEAD
=======
#include <memory>  // For std::unique_ptr
>>>>>>> d1879e35af04202e292847f7100114ca99638a73
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
<<<<<<< HEAD
    Weapon* weapon;  

public:
    // Constructor
    Transformer(const std::string& name, int energy_level, const std::string& color, int speed,
                const std::string& weapon_type, int weapon_power);

    // Destructor
    virtual ~Transformer();  // Mark as virtual

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
    virtual void displayInfo() const;  // Mark as virtual for overriding
=======
    std::unique_ptr<Weapon> weapon;
>>>>>>> d1879e35af04202e292847f7100114ca99638a73
};

#endif // TRANSFORMER_H
