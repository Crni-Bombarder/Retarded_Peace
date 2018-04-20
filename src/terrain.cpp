#include "terrain.h"

using namespace std;

vector<Terrain*> Terrain::vectorTerrain = vector<Terrain*>();

Terrain::Terrain()
{
    idImage =0;
    addTerrainToVector(this);
}
Terrain::Terrain(int _idImage)
{
    idImage = _idImage;
    addTerrainToVector(this);
}
Terrain::~Terrain() {}

int Terrain::getIdImage(void)
{
    return idImage;
}
void Terrain::setIdImage(int _idImage)
{
    idImage = _idImage;
}

Terrain* Terrain::getTerrainFromId(int _id)
{
    return vectorTerrain[_id];
}

void Terrain::addTerrainToVector(Terrain * _pterrain)
{
    vectorTerrain.push_back(_pterrain);
}
