/*Pan Vladimir st128934@student.spbu.ru
  transformers
*/
#include <string>

class Weapon {
protected:
    std::string type;
    int power;

public:
    Weapon(const std::string& type, int power) : type(type), power(power) {}
    
    std::string getType() const {
        return type;
    }
    
    int getPower() const {
        return power;
    }
};


