#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
private:
    std::string type;
    int power;

public:
    // Constructor
    Weapon(const std::string& type, int power);

    // Getters and setters
    std::string getType() const;
    void setType(const std::string& new_type);
    int getPower() const;
    void setPower(int new_power);
};

#endif // WEAPON_H
