#ifndef TILE_H
#define TILE_H

#include <vector>
#include <iostream>

using namespace std;

class Tile{
public:

  Tile();
  Tile(int _idTerrain);
  ~Tile();

  int getIdTerrain(void);
  void setIdTerrain(int _idTerrain);
  void printTile(void);
  Unit* getUnit();
  void setUnit(Unit* _unit);

private:

  int idTerrain;
  Unit* unit;

};

#endif
