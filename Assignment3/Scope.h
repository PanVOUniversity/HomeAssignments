#ifndef SCOPE_H
#define SCOPE_H

#include "Weapon.h"
#include <string>

class Scope : public Weapon {
private:
    int zoom;

public:
    Scope(const std::string& type, int power, int zoom);
    
    int getScope() const;
    void setScope(int new_scope);
    
    std::string getType() const override; 
    
    void displayInfo() const;
};

#endif
