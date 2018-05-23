#ifndef HELICOPTER_H
#define HELICOPTER_H

#include <string>
#include "air_unit.h"

class Helicopter : public AirUnit
{
public:
    Helicopter();
    ~Helicopter();

    Helicopter(string _typeName);
};

#endif
