#ifndef GAME_H
#define GAME_H

#include <thread>
#include <string>
#include <ctime>
#include <iostream>
#include <unistd.h>

#include "map.h"
#include "display.h"
#include "vector_image.h"
#include "SDL.h"

#define FRAMERATE 25

using namespace std;

class Game{

public:

  Game();
  Game(string _mapFile);
  ~Game();

  void setMapFile(string _mapFile);

  bool StartGame(void);
  void initGame(void);
  bool StopGame(void);

private:

  string mapFile;
  VectorImage libImages;
  thread* gameThread;
  Map gameMap;
  Display gameDisplay;
  bool gameRunning;

  void loop();

};

#endif
