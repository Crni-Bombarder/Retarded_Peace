#ifndef INFANTERY_H
#define INFANTERY_H

#include "land_unit.h"

#include <string>

using namespace std;

class Infantery: public LandUnit
{
public:
    Infantery();
    ~Infantery();

    Infantery(string _typeName);
};

#endif
