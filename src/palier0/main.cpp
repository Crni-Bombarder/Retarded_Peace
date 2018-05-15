#include <iostream>
#include <string>
#include <unistd.h>

#include "game.h"

int main(int argc, char* argv[])
{
    GenericInfantry genericinfantry0 =  GenericInfantry("infanterie");
    GenericInfantry genericinfantry1 =  GenericInfantry("infanterie1");
    GenericInfantry genericinfantry2 =  GenericInfantry("infanterie2");
    GenericInfantry genericinfantry3 =  GenericInfantry("infanterie3");

  Game game("map0");
  game.initGame();
  game.StartGame();

  // game.setMapFile("map1");
  // game.StartGame();

  return EXIT_SUCCESS;
}
