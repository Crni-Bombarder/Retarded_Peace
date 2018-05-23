#ifndef VEHICULES_H
#define VEHICULES_H

#include <string>
#include "land_unit.h"

class Vehicules : public LandUnit
{
public:
    Vehicules();
    ~Vehicules();

    Vehicules(string _typeName);
};

#endif
