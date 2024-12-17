/*Pan Vladimir st128934@student.spbu.ru
"Home assignment 4 - operator and constructors overloading"
*/
#include "Advantage.h"

Advantage::Advantage(const int &power):_power(power) {};

Advantage::~Advantage() = default;

void Advantage::setPower(const int &i)
{
    _power = i;
}

int Advantage::getPower() const
{
    return _power;
}

std::ostream& operator<<(std::ostream& os, const Advantage& item)
{
    os << "Advantage power: " << item.getPower();
    return os;
}