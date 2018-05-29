#include "headers/land_unit.h"

LandUnit::LandUnit(){}

LandUnit::~LandUnit(){}

LandUnit::LandUnit(string _typeName)
    : TypeUnit(_typeName)
{
    moveMalus["mer"] = -1;
}
