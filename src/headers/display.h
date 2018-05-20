#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <vector>

#include "map.h"
#include "window.h"
#include "color.h"
#include "rect.h"
#include "unit.h"
#include "vector_image.h"

#define CURSOR_IMAGE_ID 4
#define BLUE_IMAGE_ID   3
#define GREY_IMAGE_ID   3

class Display{
public:

  Display();
  Display(Map* _map, VectorImage* _vectorImage, int _screenX, int _screenY, int _tileX, int _tileY);
  Display(Map* _map, VectorImage* _vectorImage, int _tileX, int _tileY);
  ~Display();

  void enableCursor();
  void disableCursor();
  bool getCursorStatut();
  void setCursorPosition(Rect _position);
  Rect getCursorPosition();

  bool startDisplay();
  bool stopDisplay();
  bool updateDisplay();

  bool resizeWindow();

private:

  int screenX;
  int screenY;
  int tileX;
  int tileY;

  Rect posCursor;
  bool dispCursor;

  Map* gameMap;
  Window* dispWindow;
  VectorImage* vectorImage;

};

#endif
