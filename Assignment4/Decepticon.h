/*Pan Vladimir st128934@student.spbu.ru
  transformers
*/
#include "Vehicle.h"
#include "Transformer.h"

class Decepticon : public Transformer {
public:
    Decepticon(const std::string& name, int energy_level, const std::string& color, int speed,
               const std::string& weapon_type, int weapon_power, int annoyance_level,
               const std::string& preferred_excuse, const std::string& reason_for_evil,
               const std::string& vehicle_type, const std::string& vehicle_model);

    int getAnnoyanceLevel() const;
    void setAnnoyanceLevel(int new_annoyance_level);
    
    std::string getPreferredExcuse() const;
    void setPreferredExcuse(const std::string& new_preferred_excuse);
    
    std::string getReasonForEvil() const;
    void setReasonForEvil(const std::string& new_reason_for_evil);
    
    Vehicle getVehicle() const;
    
    void displayInfo() const;

private:
    int annoyance_level;
    std::string preferred_excuse;
    std::string reason_for_evil;
    Vehicle vehicle;  // Declare vehicle here
};
