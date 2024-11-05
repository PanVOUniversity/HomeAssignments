#include "Scope.h"
#include <iostream>

Scope::Scope(int type):Weapon;

void Scope::setScope(const std::string& new_scope) {
    zoom = new_scope;
}

void Scope::getType() const {
    Weapon::getType();
    std::cout << "Zoom is " << zoom<<"x";
}``