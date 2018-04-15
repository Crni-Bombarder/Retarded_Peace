#include "headers/tile.h"

Tile::Tile()
{
    id = 0;
    tileImage = NULL;
    // TO DO : init vector listTiles
}

Tile::Tile(String _imageName)
{

}

Tile::~Tile(){}

int Tile::getId(void)
{
    return id;
}

Image* Tile::getImage(void)
{
    return tileImage;
}

static Tile* Tile::getTileFromId(int _id)
{
    return listTiles.at(_id);
}

