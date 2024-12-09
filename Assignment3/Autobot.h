/*Pan Vladimir st128934@student.spbu.ru
  transformers
*/
#ifndef AUTOBOT
#define AUTOBOT

#include "Transformer.h"

class Autobot:public Transformer{
private:
    std::string _commander;
    std::string _reason_for_kindness;

public:
    Autobot(
        const std::string &name,
        const uint &power,
        const uint &speed,
        const Advantage &equipment,
        const std::string &commander,
        const std::string &reason_for_kindness
    );
    ~Autobot();

    std::string getCommander();
    void setCommander(const std::string &commander);

    std::string getReasonForKindness();
    void setReasonForKindness(const std::string &reason_for_kindness);
        
    void callComander();
};

#endif