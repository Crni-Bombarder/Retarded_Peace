#include "headers/map.h"

vector<int> mapTiles = vector<int>();
vector<string> terrainName = vector<string>();

Map::Map(){}

Map::Map(string mapName)
{
   loadMapFromFile(mapName);
}

Map::~Map(){}

bool Map::loadMapFromFile(string mapName)
{
    char buf[128];
    int idTerrain;
    char nameTerrain[256];
    ifstream mapFile;
    string mapPath = "data/maps/" + mapName + ".map";    //Be careful of mapPath (relative to Makefile)
    mapFile.open(mapPath);
    if(mapFile.bad() == true)
    {
        cout << "Erreur de chargement de la carte (fichier non ouvert)" << endl;
        return false;
    }
    mapFile.getline(buf, 128);
    while(sscanf(buf, "# %s\n", nameTerrain) > 0)
    {
      addNameTerrain(string(nameTerrain));
      mapFile.getline(buf, 128);
    }
    sscanf(buf, "$ %d %d\n", &nmbTilesX, &nmbTilesY);
    mapTiles.resize(nmbTilesX*nmbTilesY);
    for(int cmp = 0; cmp < nmbTilesY*nmbTilesY; cmp++)
    {
        if(mapFile.eof())
        {
            cout << "Erreur de chargement de la carte (fin de fichier atteint)" << endl;
            return false;
        }
        mapFile.getline(buf,128);
        sscanf(buf, "%d\n", &idTerrain);
        mapTiles[cmp].setNameTerrain(terrainName[idTerrain]);
    }
    return true;
}

int Map::getNmbTilesX(void)
{
    return nmbTilesX;
}
int Map::getNmbTilesY(void)
{
    return nmbTilesY;
}

void Map::printMap()
{
    cout << nmbTilesX << endl;
    cout << nmbTilesY << endl;
    for(int i = 0; i < nmbTilesY; i++)
    {
        for(int j = 0; j < nmbTilesX; j++)
        {
            cout << mapTiles[i*nmbTilesX + j].getNameTerrain() << " ";
        }
        cout << endl;
    }
}

Tile* Map::getTile(int _x, int _y)
{
  return &mapTiles[_y*nmbTilesX + _x];
}

Terrain* Map::getTerrainFromTiles(int _x, int _y)
{
    string nameTerrain = mapTiles[_y*nmbTilesX + _x].getNameTerrain();
    return Terrain::getTerrainFromName(nameTerrain);
}

void Map::addNameTerrain(string _nameTerrain)
{
    terrainName.push_back(_nameTerrain);
}

Unit* Map::getUnitFromTiles(int _x, int _y)
{
    return mapTiles[_y*nmbTilesX + _x].getUnit();
}
