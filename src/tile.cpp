#include "headers/tile.h"

using namespace std;

vector<Tile*> Tile::listTiles = vector<Tile*>();

Tile::Tile()
{
    idTile = listTiles.size();
    idImage = 0;
    listTiles.push_back(this);
}

Tile::Tile(int _idImage)
{
    idTile = listTiles.size();
    idImage = _idImage;
    listTiles.push_back(this);
}

Tile::~Tile(){}

int Tile::getIdTile()
{
    return idTile;
}

int Tile::getIdImage()
{
    return idImage;
}

void Tile::printVectorTile()
{
    for(int i = 0; i < listTiles.size(); i++)
    {
        getTileFromId(i)->printTile();
    }
}

void Tile::printTile()
{
    cout << "Tile : idTile : " << idTile << ", idImage : " << idImage << endl;
}

Tile* Tile::getTileFromId(int _id)
{
    return listTiles[_id];
}

