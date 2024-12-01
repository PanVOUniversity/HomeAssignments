/*Pan Vladimir st128934@student.spbu.ru
  transformers
*/
#include "Decepticon.h"
#include <iostream>
#include "Vehicle.h"

Decepticon::Decepticon(const std::string& name, int energy_level, const std::string& color, int speed,
                       const std::string& weapon_type, int weapon_power, int annoyance_level,
                       const std::string& preferred_excuse, const std::string& reason_for_evil,
                       const std::string& vehicle_type, const std::string& vehicle_model)
    : Transformer(name, energy_level, color, speed, weapon_type, weapon_power),
      annoyance_level(annoyance_level),
      preferred_excuse(preferred_excuse),
      reason_for_evil(reason_for_evil),
      vehicle(vehicle_type, vehicle_model) {}

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

Vehicle Decepticon::getVehicle() const {
    return vehicle;
}

void Decepticon::displayInfo() const {
    std::cout << "Name: " << getName() << "\n";
    std::cout << "Energy Level: " << getEnergyLevel() << "/100\n";
    std::cout << "Color: " << getColor() << "\n";
    std::cout << "Speed: " << getSpeed() << "\n";
    std::cout << "Weapon: " << getWeapon()->getType() << "\n";
    std::cout << "Weapon Power: " << getWeapon()->getPower() << "\n";
    std::cout << "Annoyance Level: " << annoyance_level << "/100\n";
    std::cout << "Preferred Excuse for Losing: " << preferred_excuse << "\n";
    std::cout << "Reason for Evilness: " << reason_for_evil << "\n";
    std::cout << "Vehicle: " << vehicle.getType() << " " << vehicle.getModel() << "\n";  // Updated for correct access
}
