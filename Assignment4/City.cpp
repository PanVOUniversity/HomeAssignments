/*Pan Vladimir st128934@student.spbu.ru
"Home assignment 4 - operator and constructors overloading"
*/
#include "City.h"

City::City() {};
City::~City() {};

int City::getBuildings()
{
    return _number_of_destroyed_buildings;
}

void City::setBuildings(const int &number)
{
    _number_of_destroyed_buildings = number;
}