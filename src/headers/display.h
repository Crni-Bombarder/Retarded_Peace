#ifndef DISPLAY_H
#define DISPLAY_H

#include <thread>
#include <mutex>

#include "map.h"
#include "window.h"

class Display{
public:

  Display();
  ~Display();

  startDisplay();
  stopDisplay();
  updateDisplay();

private:

  int screenX;
  int screenY;
  int tileX;
  int tileY;
  int nmbTileX;
  int nmbTileY;

  thread* dispThread;
  mutex* dispMutex;
  Map* gameMap;
  Window* dispWindow;

};

#endif
