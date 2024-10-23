#ifndef CRITIC_H
#define CRITIC_H

#include <string>

class Critic {
private:
    std::string name;
    int sarcasm_level;

public:
    // Constructor
    Critic(const std::string& name, int sarcasm_level);

    // Getters and setters
    std::string getName() const;
    void setName(const std::string& new_name);

    void critique() const;
};

#endif // CRITIC_H
