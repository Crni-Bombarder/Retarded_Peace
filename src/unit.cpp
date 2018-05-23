#include "unit.h"

using namespace std;

Unit::Unit(){}

Unit::Unit(string _strType, int _owner)
{
    strType = _strType;
    position = Rect(0, 0);
    moved = false;
    owner = _owner;
    PV = 100;
}

Unit::Unit(Rect _pos, string _strType, int _owner)
{
    strType = _strType;
    position = _pos;
    moved = false;
    owner = _owner;
    PV = 100;
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

int Unit::getMoveMalus(string _strTerrain)
{
    return TypeUnit::getTypeUnit(strType)->getMoveMalus(_strTerrain);
}

Rect Unit::getPosition()
{
    return position;
}

void Unit::setPosition(Rect dst)
{
  position = dst;
}

int Unit::getOwner()
{
    return owner;
}

bool Unit::hasMoved()
{
    return moved;
}

void Unit::setMoved(bool _moved)
{
    moved = _moved;
}

void Unit::setPV(int _PV)
{
    PV = _PV;
}

void Unit::printUnit()
{
    cout << endl;
    cout << "INFORMATIONS SUR l'UNITE" << endl;
    cout << "Type d'unite : " << strType << endl;
    cout << "Position : [" << position.getX() << "; " << position.getY() << "]" << endl;
    cout << "Proprietaire : Joueur " << owner << endl;
    cout << "A deja joue : " << ((moved == true)?"Oui":"Non") << endl;
    cout << endl;
    cout << "Points de vie restants : " << PV << "/100" << endl;
    cout << "Points de deplacements : " << TypeUnit::getTypeUnit(strType)->getMovePoints() << endl;
    cout << "Portee minimale : " << TypeUnit::getTypeUnit(strType)->getMinRange() << endl;
    cout << "Portee Maximale : " << TypeUnit::getTypeUnit(strType)->getMaxRange() << endl;

}
