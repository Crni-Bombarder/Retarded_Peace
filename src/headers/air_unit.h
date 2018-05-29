#ifndef AIR_UNIT_H
#define AIR_UNIT_H

#include <string>
#include "typeunit.h"

class AirUnit : public TypeUnit
{
public:
    AirUnit();
    ~AirUnit();

    AirUnit(string _typeName);
};

#endif
