/*Pan Vladimir st128934@student.spbu.ru
  transformers
*/

#ifndef MINICON_H
#define MINICON_H

#include "Transformer.h"
#include <string>

class Minicon : public Transformer{
public:
    //Constructor
    Minicon(const std::string& name, int energy_level, const std::string& color, int speed, 
            const std::string& weapon_type, int weapon_power);
};

#endif