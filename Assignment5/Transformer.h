#ifndef TRANSFORMER
#define TRANSFORMER

#include <iostream>
#include <string>
#include "City.h"
#include "Advantage.h"

class Transformer
{
private:
    std::string _name;
    uint _power;
    uint _speed;
    Advantage advantage;
    City* _city; // Pointer to associated City

public:
    Transformer();
    Transformer(
        const std::string &name,
        const uint &power,
        const uint &speed,
        const int &advantage_power,
        City* c = nullptr
    );
    ~Transformer();

    std::string getName() const;
    void setName(const std::string &name);

    uint getPower() const;
    void setPower(const uint &power);

    uint getSpeed() const;
    void setSpeed(const uint &speed);

    Advantage getEquipment() const;
    void setEquipment(const Advantage &equipment);

    City* getCity() const;
    void setCity(City* c);

    void surrender(Transformer &item);
    void attack(City &item);

    bool operator<(const Transformer& other) const;
    bool operator>(const Transformer& other) const;
    bool operator==(const Transformer& other);

    virtual void transform();
    virtual void openFire();
    virtual void ulta();
};

std::ostream& operator<<(std::ostream& os, const Transformer& item);

#endif
