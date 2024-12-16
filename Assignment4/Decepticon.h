/*Pan Vladimir st128934@student.spbu.ru
  transformers
*/
#ifndef DECEPTICON
#define DECEPTICON

#include "Transformer.h"

class Decepticon:public Transformer
{
private:
    std::string _enemy;
    std::string _reason_for_evilness;

public:
    Decepticon();
    Decepticon(
        const std::string &name,
        const uint &power,
        const uint &speed,
        const int &advantage_power,
        const std::string &enemy,
        const std::string &reason_for_evilness
    );
    ~Decepticon();

    std::string getEnemy() const;
    void setEnemy(const std::string &enemy);

    std::string getReasonForevilness() const;
    void setReasonForevilness(const std::string &reason_for_evilness);

    void threatenTheEnemy();
};

std::ostream& operator<<(std::ostream &os, const Decepticon& item);

#endif