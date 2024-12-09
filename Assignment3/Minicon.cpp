/*Pan Vladimir st128934@student.spbu.ru
  transformers
*/
#include "Minicon.h"

Minicon::Minicon(
    const std::string &name,
    const uint &power,
    const uint &speed,
    const Advantage &equipment,
    const std::string &master,
    const std::string &existance_obligation
):
    Transformer(name, power, speed, equipment),
    _master(master),
    _existance_obligation(existance_obligation) {};

Minicon::~Minicon() = default;

std::string Minicon::getMaster()
{
    return _master;
}

void Minicon::setMaster(const std::string &master)
{
    _master = master;
}

std::string Minicon::getExistanceObligation()
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