#include <iostream>
#include <string>

// Base class representing a Transformer
class Transformer {
 private:
    std::string name;          // Name of the transformer
    int energy_level;          // Energy level
    std::string color;         // Color of the transformer
    int speed;                 // Speed

 public:
    // Constructor
    Transformer(const std::string& name, int energy_level, const std::string& color, int speed)
        : name(name), energy_level(energy_level), color(color), speed(speed) {}

    // Getters and setters
    std::string getName() const { return name; }
    void setName(const std::string& new_name) { name = new_name; }

    int getEnergyLevel() const { return energy_level; }
    void setEnergyLevel(int new_energy_level) { energy_level = new_energy_level; }

    std::string getColor() const { return color; }
    void setColor(const std::string& new_color) { color = new_color; }

    int getSpeed() const { return speed; }
    void setSpeed(int new_speed) { speed = new_speed; }

    // Methods
    void accelerate() const {
        std::cout << name << " accelerates to a speed of " << speed << " km/h!" << std::endl;
    }

    void displayInfo() const {
        std::cout << "Transformer: " << name << ", Energy Level: " << energy_level
                  << ", Color: " << color << ", Speed: " << speed << " km/h" << std::endl;
    }
};

// Derived class representing an Autobot
class Autobot : public Transformer {
 private:
    std::string commander_name; // Commander name
    int mission_count;          // Number of completed missions

 public:
    // Constructor
    Autobot(const std::string& name, int energy_level, const std::string& color, int speed,
            const std::string& commander_name, int mission_count)
        : Transformer(name, energy_level, color, speed),
          commander_name(commander_name), mission_count(mission_count) {}

    // Getters and setters
    std::string getCommanderName() const { return commander_name; }
    void setCommanderName(const std::string& new_commander_name) { commander_name = new_commander_name; }

    int getMissionCount() const { return mission_count; }
    void setMissionCount(int new_mission_count) { mission_count = new_mission_count; }

    // Overriding method
    void displayInfo() const override {
        Transformer::displayInfo();
        std::cout << "Commander: " << commander_name << ", Mission Count: " << mission_count << std::endl;
    }
};

// Derived class representing a Decepticon
class Decepticon : public Transformer {
 private:
    int annoyance_level;         // Annoyance level (0-100)
    std::string preferred_excuse; // Preferred excuse for losing
    std::string reason_for_evil;   // Reason for being evil

 public:
    // Constructor
    Decepticon(const std::string& name, int energy_level, const std::string& color, int speed,
               int annoyance_level, const std::string& preferred_excuse, const std::string& reason_for_evil)
        : Transformer(name, energy_level, color, speed),
          annoyance_level(annoyance_level), preferred_excuse(preferred_excuse), reason_for_evil(reason_for_evil) {}

    // Getters and setters
    int getAnnoyanceLevel() const { return annoyance_level; }
    void setAnnoyanceLevel(int new_annoyance_level) { annoyance_level = new_annoyance_level; }

    std::string getPreferredExcuse() const { return preferred_excuse; }
    void setPreferredExcuse(const std::string& new_preferred_excuse) { preferred_excuse = new_preferred_excuse; }

    std::string getReasonForEvil() const { return reason_for_evil; }
    void setReasonForEvil(const std::string& new_reason_for_evil) { reason_for_evil = new_reason_for_evil; }

    // Overriding method
    void displayInfo() const override {
        Transformer::displayInfo();
        std::cout << "Annoyance Level: " << annoyance_level << "/100, Preferred Excuse for Losing: "
                  << preferred_excuse << ", Reason for Evilness: " << reason_for_evil << std::endl;
    }
};
