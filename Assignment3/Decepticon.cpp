#include "Decepticon.h"

Decepticon::Decepticon(
    const std::string &name,
    const uint &power,
    const uint &speed,
    const Advantage &equipment,
    const std::string &enemy,
    const std::string &reason_for_evilness
):
    Transformer(name, power, speed, equipment),
    _enemy(enemy),
    _reason_for_evilness(reason_for_evilness) {};

Decepticon::~Decepticon() = default;

std::string Decepticon::getEnemy()
{
    return _enemy;
}

void Decepticon::setEnemy(const std::string &enemy)
{
    _enemy = enemy;
}

std::string Decepticon::getReasonForevilness()
{
    return _reason_for_evilness;
}

void Decepticon::setReasonForevilness(const std::string &reason_for_evilness)
{
    _reason_for_evilness = reason_for_evilness;
}

void Decepticon::threatenTheEnemy()
{
    std::cout << _enemy << ", I'll destroy you!!!" << std::endl;
}