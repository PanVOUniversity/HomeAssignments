/*Pan Vladimir st128934@student.spbu.ru
  transformers
*/
#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include<iostream>

class Weapon {
protected:
    std::string type;
    int power;

public:
    Weapon(const std::string& type, int power) : type(type), power(power) {}

    virtual std::string getType() const {  
        return type;
    }

    int getPower() const {
        return power;
    }

    friend std::ostream& operator<<(std::ostream& os, const Weapon& weapon) {
        os << "power: " << weapon.getPower() << " type: " << weapon.getType();
        return os;
    }

    virtual ~Weapon() {}    
};


#endif
