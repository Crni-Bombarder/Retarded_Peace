#include "unit.h"

Map* Unit::gameMap = nullptr;

Unit::Unit(){}

Unit::~Unit(){}

bool Unit::move(Rect _dst)
{
    position.setX(_dst.getX());
    position.setY(_dst.getY());
}

static void Unit::setGameMap(Map* _map)
{
    gameMap = _map;
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

