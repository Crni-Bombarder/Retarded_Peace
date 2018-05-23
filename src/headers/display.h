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
#include "sprit.h"

#define CURSOR_IMAGE_ID 3
#define BLUE_IMAGE_ID   2
#define GREY_IMAGE_ID   4
#define RED_IMAGE_ID    5

class Display{
public:

  Display();
  Display(Map* _map, VectorImage* _vectorImage, int _tileScreenX, int _tileScreenY,
                                                int _sizeTileX, int _sizeTileY);
  Display(Map* _map, VectorImage* _vectorImage, int _sizeTileX, int _sizeTileY);
  ~Display();

  void enableCursor();
  void disableCursor();
  bool getCursorStatut();
  void setCursorPosition(Rect _position);
  void setScreenPosition(Rect _position);
  Rect getCursorPosition();
  Rect getScreenPosition();

  int getTileScreenX();
  int getTileScreenY();

  void moveLeft();
  void moveRight();
  void moveUp();
  void moveDown();

  bool startDisplay();
  bool stopDisplay();
  bool updateDisplay();

  bool resizeWindow();

private:

  int tileScreenX;
  int tileScreenY;
  int sizeTileX;
  int sizeTileY;

  Rect posCursor;
  Rect posScreen;

  bool dispCursor;

  Map* gameMap;
  Window* dispWindow;
  VectorImage* vectorImage;

};

#endif
