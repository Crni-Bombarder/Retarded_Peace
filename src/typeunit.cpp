#include "headers/typeunit.h"

using namespace std;

std::map<string, TypeUnit*> TypeUnit::mapTypeUnit = std::map<string, TypeUnit*>();

TypeUnit::TypeUnit(){}

TypeUnit::~TypeUnit(){}

TypeUnit::TypeUnit(string _typeName)
{
    moveMalus = std::map<string, int>();
    mapTypeUnit[_typeName] = this;
    minRange = 0;
    maxRange = 1;
    moveAttack = true;
}

int TypeUnit::getIdImage()
{
    return idImage;
}

int TypeUnit::getMoveMalus(string _terrainName)
{
    return moveMalus[_terrainName];
}

int TypeUnit::getMinRange()
{
    return minRange;
}

int TypeUnit::getMaxRange()
{
    return maxRange;
}

bool TypeUnit::canMoveAttack()
{
    return moveAttack;
}

int TypeUnit::getAttackValue(string _target)
{
    return attackValue[_target];
}

int TypeUnit::getMovePoints()
{
  return movePoints;
}

TypeUnit* TypeUnit::getTypeUnit(string _typeName)
{
    return mapTypeUnit[_typeName];
}
