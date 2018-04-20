#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "tile.h"
#include "terrain.h"

using namespace std;

class Map{

public:

  Map();
  Map(string nameMap);
  ~Map();

  bool loadMapFromFile(string mapName);

  int getNmbTilesX(void);
  int getNmbTilesY(void);
  void printMap(void);
  Terrain* getTerrainFromTiles(int _x, int _y);

private:

  vector<Tile> mapTiles;
  int nmbTilesX;
  int nmbTilesY;

};

#endif
