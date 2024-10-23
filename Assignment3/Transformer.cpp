#include "Transformer.h"
#include <iostream>

Transformer::Transformer(const std::string& name, int energy_level, const std::string& color, int speed, const std::string& weapon_type, int weapon_power)
    : name(name), energy_level(energy_level), color(color), speed(speed), weapon(std::make_unique<Weapon>(weapon_type, weapon_power)) {}

Transformer::~Transformer() {
    std::cout << "Transformer " << name << " destroyed." << std::endl;
}

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
    return weapon.get();
}

void Transformer::accelerate() const {
    std::cout << name << " accelerates to a speed of " << speed << " km/h!" << std::endl;
}

void Transformer::displayInfo() const {
    std::cout << "Transformer: " << name << ", Energy Level: " << energy_level
              << ", Color: " << color << ", Speed: " << speed << " km/h"
              << ", Weapon: " << weapon->getType() << " (Power: " << weapon->getPower() << ")" << std::endl;
}

void Transformer::callCritic(const Critic& critic) const {
    critic.critique();
}
