/*Pan Vladimir st128934@student.spbu.ru
  transformers
*/
#ifndef ADVANTAGE
#define ADVANTAGE
#include<string>
#include<iostream>

//composition
class Advantage
{

private:
    int _power;

public:
    Advantage(const int &power);
    ~Advantage();

    void setPower(const int &power);
    int getPower() const;
};

std::ostream& operator<<(std::ostream& os, const Advantage& item);

#endif