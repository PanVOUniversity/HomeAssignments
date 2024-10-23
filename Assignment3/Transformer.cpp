#include "Transformer.h"
#include <iostream>
#include <memory>


// Constructor implementation
Transformer::Transformer(const std::string& name, int energy_level, const std::string& color, int speed, 
                         const std::string& weapon_type, int weapon_power)
    : name(name), energy_level(energy_level), color(color), speed(speed) {
    weapon = new Weapon(weapon_type, weapon_power);  // Initialize the weapon (raw pointer)
}

// Getter and Setter for name
std::string Transformer::getName() const {
    return name;
}

void Transformer::setName(const std::string& new_name) {
    name = new_name;
}

// Getter and Setter for energy level
int Transformer::getEnergyLevel() const {
    return energy_level;
}

void Transformer::setEnergyLevel(int new_energy_level) {
    energy_level = new_energy_level;
}

// Getter and Setter for color
std::string Transformer::getColor() const {
    return color;
}

void Transformer::setColor(const std::string& new_color) {
    color = new_color;
}

// Getter and Setter for speed
int Transformer::getSpeed() const {
    return speed;
}

void Transformer::setSpeed(int new_speed) {
    speed = new_speed;
}

// Get the weapon
Weapon* Transformer::getWeapon() const {
    return weapon;
}

// Display information
void Transformer::displayInfo() const {
    std::cout << "Transformer: " << name
              << ", Energy Level: " << energy_level
              << ", Color: " << color
              << ", Speed: " << speed << " km/h"
              << ", Weapon: " << weapon->getType() << " (Power: " << weapon->getPower() << ")" << std::endl;
}

// Call the critic
void Transformer::callCritic(const Critic& critic) const {
    std::cout << "Critic " << critic.getName() << " makes a sarcastic remark!" << std::endl;
}

// Destructor implementation
Transformer::~Transformer() {
    delete weapon;  // Clean up the weapon memory
}
