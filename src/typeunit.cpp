#include "headers/typeunit.h"

TypeUnit::mapTypeUnit = std::map<String, TypeUnit*>();

TypeUnit::TypeUnit(){}

~TypeUnit::TypeUnit(){}

TypeUnit::TypeUnit(String _typeName)
{
    moveMalus = std::map<String, int>();
    mapTypeUnit[_typeName] = this;
}

int TypeUnit::getIdImage()
{
    return idImage;
}

int TypeUnit::getMoveMalus()

TypeUnit* TypeUnit::getTypeUnit(String _name)
{
    return mapTypeUnit[_typeName];
}
