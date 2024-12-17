/*Pan Vladimir st128934@student.spbu.ru
"Home assignment 4 - operator and constructors overloading"
*/
#ifndef CITY
#define CITY
#include<iostream>
//association
class City
{
private:
    int _number_of_destroyed_buildings = 0;

public:
    City();
    ~City();

    void setBuildings(const int &number);
    int getBuildings();
};

#endif