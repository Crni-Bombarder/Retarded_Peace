#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "tile.h"
#include "terrain.h"
#include "unit.h"
#include "rect.h"
#include "player.h"

enum CaseHighlight {
    NONE, BLUE, RED
};

using namespace std;

class Map{

public:

    Map();
    Map(string nameMap);
    ~Map();

    bool loadMapFromFile(string mapName);

    void addNameTerrain(string _nameTerrain);
    int getNmbTilesX(void);
    int getNmbTilesY(void);
    void printMap(void);
    Tile* getTile(int _x, int _y);
    Terrain* getTerrainFromTiles(int _x, int _y);
    Unit* getUnitFromTiles(int _x, int _y);
    void moveUnit(Rect src, Rect dst);

    vector<CaseHighlight> getVectorHighlight();
    CaseHighlight getHighlight(Rect _position);
    CaseHighlight getHighlight(int _x, int _y);
    void updateVectorHighlight(std::vector<Rect> _listPos, CaseHighlight _val);
    void clearVectorHighlight();
    void clearVectorHighlight(CaseHighlight highlight);

private:


    vector<CaseHighlight> vectorHighlight;

    vector<string> terrainName;
    vector<Tile> mapTiles;
    int nmbTilesX;
    int nmbTilesY;

};

#endif
