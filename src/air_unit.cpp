#include "headers/air_unit.h"

AirUnit::AirUnit(){}

AirUnit::~AirUnit(){}

AirUnit::AirUnit(string _typeName)
    : TypeUnit(_typeName)
{
    moveMalus["mer"] = 1;
    moveMalus["plaine"] = 1;
    moveMalus["montagne"] = 1;
    moveMalus["foret"] = 1;
} 
