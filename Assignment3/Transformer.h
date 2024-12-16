/*Pan Vladimir st128934@student.spbu.ru
  transformers
*/
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
    Advantage advantage;

public:
    Transformer(
        const std::string &name,
        const uint &power,
        const uint &speed,
        const int &advantage_power
        );
    ~Transformer(); 

    std::string getName() const;
    void setName(const std::string &name);

    uint getPower() const;
    void setPower(const uint &power);

    uint getSpeed() const;
    void setSpeed(const uint &speed);

    Advantage getEquipment() const;
    void setEquipment(const Advantage &equipment);
  
    void surrender(Transformer &item);
    void attack(City &item);
    
};
#endif
