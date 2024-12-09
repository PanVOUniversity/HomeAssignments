#include "Autobot.h"

Autobot::Autobot(
    const std::string &name,
    const uint &power,
    const uint &speed,
    const Advantage &equipment,
    const std::string &commander,
    const std::string &reason_for_kindness
):
    Transformer(name, power, speed, equipment),
    _commander(commander),
    _reason_for_kindness(reason_for_kindness) {};

Autobot::~Autobot() = default;

std::string Autobot::getCommander()
{
    return _commander;
}

void Autobot::setCommander(const std::string &commander)
{
    _commander = commander;
}

std::string Autobot::getReasonForKindness()
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