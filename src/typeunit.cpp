#include "headers/typeunit.h"

using namespace std;

TypeUnit::mapTypeUnit = std::map<string, TypeUnit*>();

TypeUnit::TypeUnit(){}

TypeUnit::~TypeUnit(){}

TypeUnit::TypeUnit(string _typeName)
{
    moveMalus = std::map<string, int>();
    mapTypeUnit[_typeName] = this;
}

int TypeUnit::getIdImage()
{
    return idImage;
}

int TypeUnit::getMoveMalus(string _terrainName)
{
    return moveMalus[_terrainName];
}

TypeUnit* TypeUnit::getTypeUnit(string _typeName)
{
    return mapTypeUnit[_typeName];
}
