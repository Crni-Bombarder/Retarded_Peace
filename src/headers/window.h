#ifndef WINDOW_H
#define WINDOW_H

#include <cv.h>
#include <highgui.h>
#include <string>
#include <mutex>

#include "image.h"

class Window{
public:

  Window();
  ~Window();

  bool createWindow();
  bool destroyWindow();
  void updateWindow();

  Image* getScreen();

private:

  String windowName;
  Image screen;
  int screenX;
  int screenY;
  mutex* winMutex;

};




#endif
