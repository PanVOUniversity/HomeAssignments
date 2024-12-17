/*Pan Vladimir st128934@student.spbu.ru
"Home assignment 4 - operator and constructors overloading"
*/
#include "Minicon.h"

Minicon::Minicon()
    : Transformer("Default Minicon", 0, 0, 0),
      _master("Default Master"),
      _existance_obligation("Default Existence Obligation") {}

Minicon::Minicon(
    const std::string &name,
    const uint &power,
    const uint &speed,
    const int &advantage_power,
    const std::string &master,
    const std::string &existance_obligation
):
    Transformer(name, power, speed, advantage_power),
    _master(master),
    _existance_obligation(existance_obligation) {};

Minicon::~Minicon() = default;

std::string Minicon::getMaster() const
{
    return _master;
}

void Minicon::setMaster(const std::string &master)
{
    _master = master;
}

std::string Minicon::getExistanceObligation() const
{
    return _existance_obligation;
}

void Minicon::setExistanceObligation(const std::string &existance_obligation)
{
    _existance_obligation = existance_obligation;
}

void Minicon::callMaster()
{
    std::cout << _master << ", I'll repair you!!!" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Minicon&item)
{
    os << "Name " << item.getName() << ", ";
    os << "power " << item.getPower() << ", ";
    os << item.getEquipment() << ", ";
    os << "Speed " << item.getSpeed();
    os << ", existanse obligation: " << item.getExistanceObligation();
    os << ", master: " << item.getMaster();
    return os;
}
