#include "Transformer.h"
#include <iostream>
#include <memory>
<<<<<<< HEAD

=======
>>>>>>> 00b227a6971291974367daade1deb66a914c6719

// Constructor implementation
Transformer::Transformer(const std::string& name, int energy_level, const std::string& color, int speed, 
                         const std::string& weapon_type, int weapon_power)
    : name(name), energy_level(energy_level), color(color), speed(speed), weapon(std::make_unique<Weapon>(weapon_type, weapon_power)) {}

std::string Transformer::getName() const {
    return name;
}

void Transformer::setName(const std::string& new_name) {
    name = new_name;
}

int Transformer::getEnergyLevel() const {
    return energy_level;
}

void Transformer::setEnergyLevel(int new_energy_level) {
    energy_level = new_energy_level;
}

std::string Transformer::getColor() const {
    return color;
}

void Transformer::setColor(const std::string& new_color) {
    color = new_color;
}

int Transformer::getSpeed() const {
    return speed;
}

void Transformer::setSpeed(int new_speed) {
    speed = new_speed;
}

Weapon* Transformer::getWeapon() const {
    return weapon.get();  // return raw pointer from unique_ptr
}

void Transformer::displayInfo() const {
    std::cout << "Transformer: " << name
              << ", Energy Level: " << energy_level
              << ", Color: " << color
              << ", Speed: " << speed << " km/h"
              << ", Weapon: " << weapon->getType() << " (Power: " << weapon->getPower() << ")" << std::endl;
}

Transformer::~Transformer() = default;  // Defaulted destructor since unique_ptr handles memory
