#include "Scope.h"
#include <iostream>

Scope::Scope(const std::string& type, int power, int zoom) 
    : Weapon(type, power), zoom(zoom) {}

void Scope::setScope(int new_scope) {
    zoom = new_scope;
}

int Scope::getScope() const {
    return zoom;
}

std::string Scope::getType() const {
    return "Scope with zoom level " + std::to_string(zoom) + "x";
}

void Scope::displayInfo() const {
    std::cout << "Weapon type: " << getType() << ", Power: " << getPower() 
              << ", Zoom level: " << zoom << "x" << std::endl;
}
