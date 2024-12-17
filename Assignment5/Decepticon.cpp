/*Pan Vladimir st128934@student.spbu.ru
"Home assignment 5 - virtual methods creation and use*/
#include "Decepticon.h"

Decepticon::Decepticon()
    : Transformer("Default Decepticon", 0, 0, 0),
      _enemy("Default Enemy"),
      _reason_for_evilness("Default Reason for Evilness") {}

Decepticon::Decepticon(
    const std::string &name,
    const uint &power,
    const uint &speed,
    const int &advantage_power,
    const std::string &enemy,
    const std::string &reason_for_evilness
):
    Transformer(name, power, speed, advantage_power),
    _enemy(enemy),
    _reason_for_evilness(reason_for_evilness) {};

Decepticon::~Decepticon() = default;

std::string Decepticon::getEnemy() const
{
    return _enemy;
}

void Decepticon::setEnemy(const std::string &enemy)
{
    _enemy = enemy;
}

std::string Decepticon::getReasonForevilness() const
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

std::ostream&operator<<(std::ostream& os,const Decepticon& item)
{
    os << "Name " << item.getName() << ", ";
    os << "power " << item.getPower() << ", ";
    os << item.getEquipment() << ", ";
    os << "Speed " << item.getSpeed();
    os << ", reason for evilness: " << item.getReasonForevilness();
    os << ", enemy" << item.getEnemy();
    return os;
}

void Decepticon::transform()
{
    std::cout << "Decepticon, transform" << std::endl;
}

void Decepticon::ulta()
{
    std::cout << "Decepticon, ulta" << std::endl;
}

void Decepticon::openFire()
{
    std::cout << "Decepticon, openFire" << std::endl;
}
