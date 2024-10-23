#ifndef CRITIC_H
#define CRITIC_H

#include <string>

class Critic {
 private:
    std::string name;
    int sarcasm_level;

 public:
    Critic(const std::string& name, int sarcasm_level);
    void critique() const;
};

#endif // CRITIC_H
