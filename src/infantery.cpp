#include "headers/infantery.h"

Infantery::Infantery(){}

Infantery::~Infantery(){}

Infantery::Infantery(string _typeName)
     : LandUnit(_typeName)
 {
     movePoints = 3;
     moveMalus["plaine"] = 1;

     minRange = 0;
     maxRange = 1;
     attackValue["infantery"] = 50;
     attackValue["artillery"] = 30;
     attackValue["helicopter"] = 20;
 }
