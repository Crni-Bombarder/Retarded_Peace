#ifndef GAME_H
#define GAME_H

#include <thread>
#include <mutex>
#include <string>

#include "map.h"
#include "display.h"
#include "vector_image.h"

class Game{

public:

  Game();
  Game(String mapFile);
  ~Game();

  void setMapFile(String mapFile);

  bool StartGame(void);
  bool StopGame(void);

private:

  String mapFile;
  VectorImage libImages;
  thread gameThread;
  Map gameMap;
  Display gameDisplay;
  bool gameRunning;

  void loop();

};

#endif
