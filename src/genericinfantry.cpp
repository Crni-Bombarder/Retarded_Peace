#include "headers/genericinfantry.h"

GenericInfantry::GenericInfantry(){}

GenericInfantry::~GenericInfantry(){}

GenericInfantry::GenericInfantry(string _typeName)
     : TypeUnit(_typeName)
 {
     idImage = 2;
     movePoints = 4;
     moveMalus["plaine"] = 1;
     moveMalus["mer"] = -1;

     minRange = 0;
     maxRange = 1;
     attackValue["infanterie"] = 50;
 }
