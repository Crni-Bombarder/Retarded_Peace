#ifndef LAND_UNIT_H
#define LAND_UNIT_H

#include <string>
#include "typeunit.h"

using namespace std;

class LandUnit : public TypeUnit
{
public:
    LandUnit();
    ~LandUnit();

    LandUnit(string _typeName);
};

#endif
