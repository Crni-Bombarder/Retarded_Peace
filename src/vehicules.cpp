#include "headers/vehicules.h"

Vehicules::Vehicules(){}

Vehicules::~Vehicules(){}

Vehicules::Vehicules(string _typeName)
    : LandUnit(_typeName)
{
    moveMalus["montagne"] = -1;
}
