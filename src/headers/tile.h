#ifndef TILE_H
#define TILE_H

#include <vector>
#include <iostream>

using namespace std;

class Tile{
public:

  Tile();
  Tile(int _idImage);
  ~Tile();

  int getIdTile(void);
  int getIdImage(void);
  static Tile* getTileFromId(int _id);
  static void printVectorTile(void);
  void printTile(void);

private:

  int idTile;
  int idImage;
  static vector<Tile*> listTiles;

};

#endif
