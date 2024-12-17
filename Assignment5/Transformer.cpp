/*Pan Vladimir st128934@student.spbu.ru
"Home assignment 4 - operator and constructors overloading"
*/
#include "Transformer.h"

Transformer::Transformer()
    : _name("Default Transformer"), _power(0), _speed(0), advantage(0)
{
    std::cout << "Default constructor called.\n";
};

Transformer::Transformer(
    const std::string &name,
    const uint &power,
    const uint &speed,
    const int &advantage_power,
    City* c
):
    _name(name),
    _power(power),
    _speed(speed),
    advantage(advantage_power),
    _city(c)
{}
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



City* Transformer::getCity() const
{
    return _city;
}

void Transformer::setCity(City* c)
{
    _city = c;
}

void Transformer::attack(City &item)
{
    if (&item == _city)
    {
        std::cout << _name << " is attacking its associated city!\n";
    }
    item.setBuildings((item.getBuildings() + _power));

}

std::ostream& operator<<(std::ostream& os, const Transformer& item)
{
    os << "Name " << item.getName() << ", ";
    os << "power " << item.getPower() << ", ";
    os << item.getEquipment() << ", ";
    os << "Speed " << item.getSpeed();
    return os;
}

bool Transformer::operator<(const Transformer& other) const
{
    return _power < other._power;
}

bool Transformer::operator>(const Transformer& other) const
{
    return _power > other._power;
}

bool Transformer::operator==(const Transformer& other)
{
    return _power == other.getPower();
}

void Transformer::transform()
{
    std::cout << "Transformer, transform" << std::endl;
}

void Transformer::ulta()
{
    std::cout << "Transformer, ulta" << std::endl;
}

void Transformer::openFire()
{
    std::cout << "Transformer, openFire"<<std::endl;
}
