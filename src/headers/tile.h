#ifndef TILE_H
#define TILE_H

#include <string>
#include <vector>

#include "image.h"
#include "tile.h"

class Tile{

public:

  Tile();
  Tile(String imageName);
  ~Tile();

  int getId(void);
  Image* getImage(void);
  static Tile* getTileFromId(int _id);

private:

  int id;
  Image* tileImage;
  static vector<Tile*> listTiles;

};

#endif
