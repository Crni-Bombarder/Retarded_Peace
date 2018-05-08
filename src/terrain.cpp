#include "terrain.h"

using namespace std;

map<string, Terrain*> Terrain::vectorTerrain = map<string, Terrain*>();

Terrain::Terrain()
{
    idImage =0;
    addTerrainToVector(this);
}
Terrain::Terrain(int _idImage, string _terrainName)
{
    nameTerrain = _terrainName;
    idImage = _idImage;
    addTerrainToVector(this);
}
Terrain::~Terrain() {}

string Terrain::getNameTerrain(void)
{
    return nameTerrain;
}

int Terrain::getIdImage(void)
{
    return idImage;
}
void Terrain::setIdImage(int _idImage)
{
    idImage = _idImage;
}

Terrain* Terrain::getTerrainFromName(string _name)
{
    return vectorTerrain[_name];
}

void Terrain::addTerrainToVector(Terrain * _pterrain)
{
    vectorTerrain.emplace(_pterrain->getNameTerrain(), _pterrain);
}
