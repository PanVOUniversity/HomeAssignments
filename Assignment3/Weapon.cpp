#include "Weapon.h"

Weapon::Weapon(const std::string& type, int power) : type(type), power(power) {}

std::string Weapon::getType() const {
    return type;
}

int Weapon::getPower() const {
    return power;
}
