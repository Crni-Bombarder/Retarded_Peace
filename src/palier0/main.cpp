#include <iostream>
#include <string>

#include "../headers/game.h"

int main(int argc, char* argv[])
{
  Game game("map0");
  game.initGame();
  game.StartGame();
  sleep(10);
  game.StopGame();

  game.setMapFile("map1");
  game.StartGame();
  sleep(10);
  game.StopGame();

  return EXIT_SUCCESS;
}
