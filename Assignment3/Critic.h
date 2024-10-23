#ifndef CRITIC_H
#define CRITIC_H

#include <string>

class Critic {
private:
    std::string name;

public:
    // Constructor
    Critic(const std::string& name);

    // Getters and setters
    std::string getName() const;
    void setName(const std::string& new_name);
};

#endif // CRITIC_H
