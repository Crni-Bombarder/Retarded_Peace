#include "headers/tile.h"

using namespace std;

Tile::Tile()
{
    nameTerrain = "void";
    unit = nullptr;
}

Tile::Tile(string _nameTerrain)
{
    nameTerrain = _nameTerrain;
    unit = nullptr;
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
