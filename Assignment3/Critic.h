#ifndef CRITIC_H
#define CRITIC_H

#include <string>

class Critic {
public:
    Critic(const std::string& name, int sarcasm_level);
    std::string critique() const;

private:
    std::string name;
    int sarcasm_level;
};

#endif 
