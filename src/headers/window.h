#ifndef WINDOW_H
#define WINDOW_H

#include <cv.hpp>
#include <highgui.h>
#include <string>

#include "image.h"

using namespace cv;

class Window{
public:

  Window();
  Window(unsigned int _screenX, unsigned int _screenY);
  Window(unsigned int _screenX, unsigned int _screenY, string _windowName);
  ~Window();

  bool createWin();
  bool destroyWin();
  void updateWin();

  Image* getScreen();

private:

  String windowName;
  Image screen;
  int screenX;
  int screenY;

};




#endif
