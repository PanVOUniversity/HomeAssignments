/*Pan Vladimir st128934@student.spbu.ru
"Home assignment 4 - operator and constructors overloading"
*/
#ifndef MINICON
#define MINICON

#include "Transformer.h"

class Minicon:public Transformer
{
private:
    std::string _master;
    std::string _existance_obligation;

public:
    Minicon();
    Minicon(
        const std::string &name,
        const uint &power,
        const uint &speed,
        const int &advantage_power,
        const std::string &master,
        const std::string &existance_obligation
    );
    ~Minicon();

    std::string getMaster() const;
    void setMaster(const std::string &master);

    std::string getExistanceObligation() const;
    void setExistanceObligation(const std::string &existance_obligation);

    void callMaster();
};

std::ostream& operator<<(std::ostream& os, const Minicon& item);

#endif