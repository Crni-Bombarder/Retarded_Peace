#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <iostream>

#include "SDL.h"
#include "image.h"
#include "color.h"
#include "rect.h"

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

  void blitImage(Image* _image, Rect* src, Rect* dst);
  void clearWin(Color);

  static void initVideoDriver(void);
  static void quitVideoDriver(void);

private:

  string windowName;
  SDL_Window* window;
  SDL_Renderer* renderer;
  int screenX;
  int screenY;

};




#endif
