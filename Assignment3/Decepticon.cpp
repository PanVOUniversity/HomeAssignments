#include "Decepticon.h"
#include <iostream>

Decepticon::Decepticon(const std::string& name, int energy_level, const std::string& color, int speed, const std::string& weapon_type, int weapon_power,
                       int annoyance_level, const std::string& preferred_excuse, const std::string& reason_for_evil)
    : Transformer(name, energy_level, color, speed, weapon_type, weapon_power),
      annoyance_level(annoyance_level), preferred_excuse(preferred_excuse), reason_for_evil(reason_for_evil) {}

int Decepticon::getAnnoyanceLevel() const {
    return annoyance_level;
}

void Decepticon::setAnnoyanceLevel(int new_annoyance_level) {
    annoyance_level = new_annoyance_level;
}

std::string Decepticon::getPreferredExcuse() const {
    return preferred_excuse;
}

void Decepticon::setPreferredExcuse(const std::string& new_preferred_excuse) {
    preferred_excuse = new_preferred_excuse;
}

std::string Decepticon::getReasonForEvil() const {
    return reason_for_evil;
}

void Decepticon::setReasonForEvil(const std::string& new_reason_for_evil) {
    reason_for_evil = new_reason_for_evil;
}

void Decepticon::displayInfo() const {
    Transformer::displayInfo();
    std::cout << "Annoyance Level: " << annoyance_level << "/100, Preferred Excuse for Losing: "
              << preferred_excuse << ", Reason for Evilness: " << reason_for_evil << std::endl;
}
