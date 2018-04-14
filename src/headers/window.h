#ifndef WINDOW_H
#define WINDOW_H

#include <cv.hpp>
#include <highgui.h>
#include <string>
#include <mutex>

#include "image.h"

using namespace cv;

class Window{
public:

  Window();
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
  mutex* winMutex;

};




#endif
