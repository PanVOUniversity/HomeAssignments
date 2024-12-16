/*Pan Vladimir st128934@student.spbu.ru
  transformers
*/
#include "Transformer.h"


Transformer::Transformer(
    const std::string &name,
    const uint &power,
    const uint &speed,
    const int &advantage_power):
    _name(name),
    _power(power),
    _speed(speed),
    advantage(advantage_power){};

Transformer::~Transformer() = default;

std::string Transformer::getName() const
{
    return _name;
}

Advantage Transformer::getEquipment() const
{
    return advantage;
}

uint Transformer::getSpeed() const
{
    return _speed;
}

uint Transformer::getPower() const
{
    return _power;
}

void Transformer::setSpeed(const uint &speed)
{
    _speed = speed;
}

void Transformer::setEquipment(const Advantage &equipment)
{
    advantage = equipment;
}

void Transformer::setName(const std::string &name)
{
    _name = name;
}

void Transformer::setPower(const uint &power)
{
    _power =  power;
}

void Transformer::surrender(Transformer &item)
{
    item.setPower(0);
    Advantage no_advantage = Advantage(0);
    item.setName("scrap-metal");
    item.setEquipment(no_advantage);
    item.setSpeed(0);
}

void Transformer::attack(City &item)
{
    item.setBuildings((item.getBuildings() + _power));
}

