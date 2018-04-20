#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "tile.h"

using namespace std;

class Map{

public:

  Map();
  Map(string nameMap);
  ~Map();

  bool loadMapFromFile(string mapName);

  void printMap(void);

private:

  vector<Tile> mapTiles;
  int nmbTilesX;
  int nmbTilesY;

};

#endif
