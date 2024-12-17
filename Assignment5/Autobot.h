/*Pan Vladimir st128934@student.spbu.ru
"Home assignment 4 - operator and constructors overloading"
*/
#ifndef AUTOBOT
#define AUTOBOT

#include "Transformer.h"


class Autobot:public Transformer
{
private:
    std::string _commander;
    std::string _reason_for_kindness;

public:
    Autobot();
    Autobot(
        const std::string &name,
        const uint &power,
        const uint &speed,
        const int &advantage_power,
        const std::string &commander,
        const std::string &reason_for_kindness
    );
    ~Autobot();

    std::string getCommander() const;
    void setCommander(const std::string &commander);

    std::string getReasonForKindness() const;
    void setReasonForKindness(const std::string &reason_for_kindness);

    void callComander();

    void transform() override;
    void openFire() override;
    void ulta() override;

    
};

std::ostream& operator<<(std::ostream& os, const Autobot& item);

#endif