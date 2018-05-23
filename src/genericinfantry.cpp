#include "headers/genericinfantry.h"

GenericInfantry::GenericInfantry(){}

GenericInfantry::~GenericInfantry(){}

GenericInfantry::GenericInfantry(string _typeName)
     : TypeUnit(_typeName)
 {
     movePoints = 4;
     moveMalus["plaine"] = 1;
     moveMalus["mer"] = -1;

     minRange = 0;
     maxRange = 1;
     attackValue["infantery"] = 50;
     attackValue["artillery"] = 30;
 }
