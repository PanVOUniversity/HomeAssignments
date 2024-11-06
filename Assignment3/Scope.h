#ifndef SCOPE_H
#define SCOPE_H

#include "Weapon.h"

class Scope : public Weapon {
private:
    int zoom;

public:
//constructor
    Scope(int zoom);


//Getters and setters
    int getScope() const;
    void setScope (std::string new_scope);

//override
    void getType const override;
}

#endif;