#ifndef TRANSFORMER
#define TRANSFORMER

#include <iostream>
#include <string>
#include "City.h"
#include "Advantage.h"

class Transformer{
private:
    std::string _name;
    uint _power;
    uint _speed;
    Advantage _equipment;

public:
    Transformer(
        const std::string &name,
        const uint &power,
        const uint &speed,
        const Advantage &equipment
        );
    ~Transformer(); 

    std::string getName();
    void setName(const std::string &name);

    uint getPower();
    void setPower(const uint &power);

    uint getSpeed();
    void setSpeed(const uint &speed);

    Advantage getEquipment();
    void setEquipment(const Advantage &equipment);
  
    void surrender(Transformer &item);
    void attack(City &item);
    
};
#endif
