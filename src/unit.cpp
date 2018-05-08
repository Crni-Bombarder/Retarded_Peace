#include "unit.h"

Unit::Unit(){}

Unit::~Unit(){}

void Unit::move(Rect _dst)
{
    position.setX(_dst.getX());
    position.setY(_dst.getY());
}

int Unit::getPV()
{
    return PV;
}

int Unit::getStrType()
{
    return strType;
}

int Unit::getIdImage()
{
    return TypeUnit::getTypeUnit(strType)->getIdImage();
}

int Unit::getMoveMalus(String _strTerrain)
{
    return TypeUnit::getTypeUnit(strType)->getMoveMalus(_strTerrain);
}

Rect Unit::getPosition()
{
    return position;
}

int Unit::getOwner()
{
    return owner;
}

bool Unit::hasMoved()
{
    return moved;
}

void Unit::setPV(int _PV)
{
    PV = _PV;
}
