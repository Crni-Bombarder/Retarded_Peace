#include "headers/genericartillery.h"

GenericArtillery::GenericArtillery(){}

GenericArtillery::~GenericArtillery(){}

GenericArtillery::GenericArtillery(string _typeName)
     : TypeUnit(_typeName)
 {
     idImage = 7;
     movePoints = 2;
     moveMalus["plaine"] = 1;
     moveMalus["mer"] = -1;

     moveAttack = false;

     minRange = 2;
     maxRange = 3;
     attackValue["infanterie"] = 80;
     attackValue["artillery"] = 80;
 }
