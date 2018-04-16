#ifndef WINDOW_H
#define WINDOW_H

#include <string>

#include "SDL.h"
#include "image.h"

using namespace std;

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

  string windowName;
  Image* screen;
  int screenX;
  int screenY;

};




#endif
