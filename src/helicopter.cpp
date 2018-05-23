#include "headers/helicopter.h"

Helicopter::Helicopter(){}

Helicopter::~Helicopter(){}

Helicopter::Helicopter(string _typeName)
    : AirUnit(_typeName)
{
    movePoints = 6;

    minRange = 0;
    maxRange = 1;
    attackValue["infantery"] = 40;
    attackValue["artillery"] = 40;
    attackValue["helicopter"] = 30;
}
