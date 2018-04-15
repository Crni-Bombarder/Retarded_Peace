#ifndef TILE_H
#define TILE_H

#include <string.h>
#include <vector.h>

#include "image.h"

class Tile{
public:

  Tile();
  Tile(String _imageName);
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
