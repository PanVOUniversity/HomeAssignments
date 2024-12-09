/*Pan Vladimir st128934@student.spbu.ru
  transformers
*/
#ifndef MINICON
#define MINICON

#include "Transformer.h"

class Minicon:public Transformer{
private:
    std::string _master;
    std::string _existance_obligation;

public:
    Minicon(
        const std::string &name,
        const uint &power,
        const uint &speed,
        const Advantage &equipment,
        const std::string &master,
        const std::string &existance_obligation
    );
    ~Minicon();

    std::string getMaster();
    void setMaster(const std::string &master);

    std::string getExistanceObligation();
    void setExistanceObligation(const std::string &existance_obligation);
        
    void callMaster();
};

#endif