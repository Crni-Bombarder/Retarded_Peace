#include "headers/genericinfantry.h"

GenericInfantry::GenericInfantry(){}

GenericInfantry::~GenericInfantry(){}

GenericInfantry::GenericInfantry(string _typeName)
     : TypeUnit(_typeName)
 {
     idImage = 2;
     moveMalus["plaine"] = 1;
     moveMalus["mer"] = -1;
 }
