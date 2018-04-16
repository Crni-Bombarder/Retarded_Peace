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
    ifstream mapFile;
    string mapPath = "../src/data/maps/" + mapName + ".map";
    mapFile.open(mapPath);
    if(mapFile.bad())
    {
        cout << "Erreur de chargement de la carte (fichier non ouvert)" << endl;
        return false;
    }
    mapFile.getline(buf, 128);
    cout << buf << endl;
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
        cout << buf << endl;
        sscanf(buf, "%d\n", &mapTiles[cmp]);
    }
    return true;
}

void Map::printMap()
{
    for(int i = 0; i < nmbTilesY; i++)
    {
        for(int j = 0; i < nmbTilesX; j++)
        {
            cout << mapTiles[i*nmbTilesX + j] << " ";
        }
        cout << endl;
    }
}