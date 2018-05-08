#include "unit.h"

using namespace std;

Unit::Unit(){}

Unit::Unit(string _strType, int _owner)
{
    strType = _strType;
    position = Rect(0, 0);
    moved = false;
    owner = _owner;
    PV = 10;
}

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

string Unit::getStrType()
{
    return strType;
}

int Unit::getIdImage()
{
    return TypeUnit::getTypeUnit(strType)->getIdImage();
}

int Unit::getMoveMalus(string _strTerrain)
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
