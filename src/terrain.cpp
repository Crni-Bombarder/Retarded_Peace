#include "terrain.h"

using namespace std;

map<string, Terrain*> Terrain::vectorTerrain = map<string, Terrain*>();

Terrain::Terrain()
{
    idImage = 0;
    addTerrainToVector(this);
}
Terrain::Terrain(int _idImage, string _terrainName, int _defenseValue)
{
    nameTerrain = _terrainName;
    idImage = _idImage;
    defenseValue = _defenseValue;
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

int Terrain::getDefenseValue()
{
    return defenseValue;
}

Terrain* Terrain::getTerrainFromName(string _name)
{
    return vectorTerrain[_name];
}

map<string, Terrain*> Terrain::getMapTerrain()
{
    return vectorTerrain;
}

void Terrain::addTerrainToVector(Terrain * _pterrain)
{
    vectorTerrain.emplace(_pterrain->getNameTerrain(), _pterrain);
}
