#include "unit.h"

Unit::Unit(){}

Unit::~Unit(){}

bool Unit::move(Rect _dst)
{
    position.setX(_dst.getX());
    position.setY(_dst.getY());
}

int Unit::getPV()
{
    return PV;
}

int Unit::getIdType()
{
    return idType;
}

int Unit::getIdImage()
{
    return idImage;
}

void Unit::setPV(int _PV)
{
    PV = _PV;
}
