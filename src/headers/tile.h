#ifndef TILE_H
#define TILE_H

#include <vector>
#include <iostream>
#include <string>

#include "unit.h"

using namespace std;

class Tile{
public:

  Tile();
  Tile(string _nameTerrain);
  ~Tile();

  string getNameTerrain(void);
  void setNameTerrain(string _nameTerrain);
  void printTile(void);
  Unit* getUnit();
  void setUnit(Unit* _unit);

private:

  string nameTerrain;
  Unit* unit;

};

#endif
