#include "headers/map.h"

vector<int> mapTiles = vector<int>();

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
    ifstream mapFile;
    string mapPath = "data/maps/" + mapName + ".map";    //Be careful of mapPath (relative to Makefile)
    mapFile.open(mapPath);
    if(mapFile.bad() == true)
    {
        cout << "Erreur de chargement de la carte (fichier non ouvert)" << endl;
        return false;
    }
    mapFile.getline(buf, 128);
    sscanf(buf, "# %d %d\n", &nmbTilesX, &nmbTilesY);
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
        mapTiles[cmp].setIdTerrain(idTerrain);
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
            cout << mapTiles[i*nmbTilesX + j].getIdTerrain() << " ";
        }
        cout << endl;
    }
}

Terrain* Map::getTerrainFromTiles(int _x, int _y)
{
    int idTerrain = mapTiles[_y*nmbTilesX + _x].getIdTerrain();
    return Terrain::getTerrainFromId(idTerrain);
}
