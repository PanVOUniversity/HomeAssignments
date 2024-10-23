#include "Critic.h"
#include <iostream>

Critic::Critic(const std::string& name, int sarcasm_level) : name(name), sarcasm_level(sarcasm_level) {}

void Critic::critique() const {
    std::cout << name << ": " << "Nice try, really." << std::endl;
}
