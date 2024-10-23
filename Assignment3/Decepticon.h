#ifndef DECEPTICON_H
#define DECEPTICON_H

#include "Transformer.h"

class Decepticon : public Transformer {
 private:
    int annoyance_level;
    std::string preferred_excuse;
    std::string reason_for_evil;

 public:
    Decepticon(const std::string& name, int energy_level, const std::string& color, int speed, const std::string& weapon_type, int weapon_power,
               int annoyance_level, const std::string& preferred_excuse, const std::string& reason_for_evil);

    int getAnnoyanceLevel() const;
    void setAnnoyanceLevel(int new_annoyance_level);
    std::string getPreferredExcuse() const;
    void setPreferredExcuse(const std::string& new_preferred_excuse);
    std::string getReasonForEvil() const;
    void setReasonForEvil(const std::string& new_reason_for_evil);

    void displayInfo() const override;
};

#endif // DECEPTICON_H
