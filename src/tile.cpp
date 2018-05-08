#include "headers/tile.h"

using namespace std;

Tile::Tile()
{
    idTerrain = 0;
    unit = nullptr;
}

Tile::Tile(int _idTerrain)
{
    idTerrain = _idTerrain;
    unit = nullptr;
}

Tile::~Tile(){}

int Tile::getIdTerrain(void)
{
    return idTerrain;
}

void Tile::setIdTerrain(int _idTerrain)
{
    idTerrain = _idTerrain;
}

void Tile::printTile()
{
    cout << "Tile : idTerrain : " << idTerrain << endl;
}

Unit* Tile::getUnit()
{
  return unit;
}

void Tile::setUnit(Unit* _unit)
{
  unit = _unit;
}
