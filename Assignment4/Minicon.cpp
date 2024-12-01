#include "Minicon.h"
#include<iostream>

Minicon::Minicon(const std::string& name, int energy_level, const std::string& color, int speed, 
                 const std::string& weapon_type, int weapon_power)
    : Transformer(name, energy_level, color, speed, weapon_type, weapon_power){}