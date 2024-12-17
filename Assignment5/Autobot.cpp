/*Pan Vladimir st128934@student.spbu.ru
"Home assignment 4 - operator and constructors overloading"
*/
#include "Autobot.h"

Autobot::Autobot()
    : Transformer("Default Autobot", 0, 0, 0),
      _commander("Default Commander"),
      _reason_for_kindness("Default Reason") {}

Autobot::Autobot(
    const std::string &name,
    const uint &power,
    const uint &speed,
    const int &advantage_power,
    const std::string &commander,
    const std::string &reason_for_kindness
):
    Transformer(name, power, speed, advantage_power),
    _commander(commander),
    _reason_for_kindness(reason_for_kindness) {};

Autobot::~Autobot() = default;

std::string Autobot::getCommander() const
{
    return _commander;
}

void Autobot::setCommander(const std::string &commander)
{
    _commander = commander;
}

std::string Autobot::getReasonForKindness() const
{
    return _reason_for_kindness;
}

void Autobot::setReasonForKindness(const std::string &reason_for_kindness)
{
    _reason_for_kindness = reason_for_kindness;
}

void Autobot::callComander()
{
    std::cout << _commander << "!!!" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Autobot& item)
{
    os << "Name " << item.getName() << ", ";
    os << "power " << item.getPower() << ", ";
    os << item.getEquipment() << ", ";
    os << "Speed " << item.getSpeed() << ", ";
    os << "reason for kindness: "<< item.getReasonForKindness() << ", ";
    os << "commander: " << item.getCommander();
    return os;

}

void Autobot::transform()
{
    std::cout << "Autobot, transform" << std::endl;
}

void Autobot::ulta()
{
    std::cout << "Autobot, ulta" << std::endl;
}

void Autobot::openFire()
{
    std::cout << "Autobot, openFire" << std::endl;
}