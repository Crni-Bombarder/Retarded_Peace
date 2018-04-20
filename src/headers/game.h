#ifndef GAME_H
#define GAME_H

#include <thread>
#include <string>
#include <ctime>

#include "map.h"
#include "display.h"
#include "vector_image.h"

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
