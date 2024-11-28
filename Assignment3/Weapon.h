/*Pan Vladimir st128934@student.spbu.ru
  transformers
*/
#ifndef WEAPON_H
#define WEAPON_H

#include <string>

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
};

#endif
