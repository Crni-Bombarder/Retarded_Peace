#include <iostream>
#include <string>

#include "../headers/game.h"

int main(int argc, char* argv[])
{
  Game game(FICHIER_MAP_0);
  game.StartGame();
  sleep(10);
  game.StopGame();

  game.setMapFile(FICHIER_MAP_1);
  game.StartGame();
  sleep(10);
  game.StopGame();

  return EXIT_SUCCESS;
}
