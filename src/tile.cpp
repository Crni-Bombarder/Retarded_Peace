#include "headers/tile.h"

using namespace std;

Tile::Tile()
{
    nameTerrain = "void";
}

Tile::Tile(string _nameTerrain)
{
    nameTerrain = _nameTerrain;
}

Tile::~Tile(){}

string Tile::getNameTerrain(void)
{
    return nameTerrain;
}

void Tile::setNameTerrain(string _nameTerrain)
{
    nameTerrain = _nameTerrain;
}

void Tile::printTile()
{
    cout << "Tile : nameTerrain : " << nameTerrain << endl;
}

Unit* Tile::getUnit()
{
  return unit;
}

void Tile::setUnit(Unit* _unit)
{
  unit = _unit;
}
