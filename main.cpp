#include <iostream>
#include <string>

class Transformer {
private:
    std::string name;
    int energyLevel;  
    std::string color; 
    int speed;         

public:
    // Constructor
    Transformer(const std::string& name, int energyLevel, const std::string& color, int speed) 
        : name(name), energyLevel(energyLevel), color(color), speed(speed) {}

    // Getters and setters
    std::string getName() const { return name; }
    void setName(const std::string& newName) { name = newName; }

    int getEnergyLevel() const { return energyLevel; }
    void setEnergyLevel(int newEnergyLevel) { energyLevel = newEnergyLevel; }

    std::string getColor() const { return color; }
    void setColor(const std::string& newColor) { color = newColor; }

    int getSpeed() const { return speed; }
    void setSpeed(int newSpeed) { speed = newSpeed; }

    // Methods
    void accelerate() const {
        std::cout << name << " accelerates to a speed of " << speed << " km/h!" << std::endl;
    }

    void displayInfo() const {
        std::cout << "Transformer: " << name << ", Energy Level: " << energyLevel << ", Color: " << color 
                  << ", Speed: " << speed << " km/h" << std::endl;
    }
};
