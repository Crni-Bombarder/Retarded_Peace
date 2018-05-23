#include "headers/artillery.h"

Artillery::Artillery(){}

Artillery::~Artillery(){}

Artillery::Artillery(string _typeName)
     : Vehicules(_typeName)
 {
     movePoints = 3;
     moveMalus["plaine"] = 1;

     moveAttack = false;

     minRange = 2;
     maxRange = 3;
     attackValue["infantery"] = 80;
     attackValue["artillery"] = 50;
 }
