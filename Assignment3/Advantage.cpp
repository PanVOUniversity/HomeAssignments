#include "Advantage.h"

Advantage::Advantage(const int &power):_power(power) {};

Advantage::~Advantage() = default;

void Advantage::setPower(const int &i)
{
    _power = i;
}

int Advantage::getPower()
{
    return _power;
}