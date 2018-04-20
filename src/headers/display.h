#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>

#include "map.h"
#include "window.h"
#include "color.h"
#include "rect.h"
#include "vector_image.h"

class Display{
public:

  Display();
  Display(Map* _map, VectorImage* _vectorImage, int _screenX, int _screenY, int _tileX, int _tileY);
  Display(Map* _map, VectorImage* _vectorImage, int _tileX, int _tileY);
  ~Display();

  bool startDisplay();
  bool stopDisplay();
  bool updateDisplay();

private:

  int screenX;
  int screenY;
  int tileX;
  int tileY;

  Map* gameMap;
  Window* dispWindow;
  VectorImage* vectorImage;

};

#endif
