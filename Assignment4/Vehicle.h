/*Pan Vladimir st128934@student.spbu.ru
  transformers
*/
#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
public:
    Vehicle(const std::string& type, const std::string& model)
        : type(type), model(model) {}

    std::string getType() const { return type; }
    std::string getModel() const { return model; }

private:
    std::string type;
    std::string model;
};

#endif
