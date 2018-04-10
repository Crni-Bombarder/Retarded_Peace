#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>

#include "tile.h"

class Map{

public:

  Map();
  Map(String nameMap);
  ~Map();

  bool loadMapFromFile(String mapFile);

private:

  vector<Tile> mapTiles;
  int nmbTilesX;
  int nmbTilesY;


};

#endif
