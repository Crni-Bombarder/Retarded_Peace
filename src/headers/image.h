#ifndef IMAGE_H
#define IMAGE_H

#include <string.h>

#include "color.h"
#include "SDL.h"
#include "SDL_image.h"

using namespace std;

class Image{
public:

  Image();
  Image(int _x, int _y);    //Made an empty image of size x and y
  Image(string _namefile);  //Load the image from a image file
  ~Image();

  int getSizeX(void);
  int getSizeY(void);
  Color getPixel(int _x, int _y);
  //void resizeImg(int _sizeX, int _sizeY);
  SDL_Texture* getTexture();   //Return the pointer to the SDL_Surface

  void print(void);

  static void initLoadingLibrary(SDL_Renderer* _format);
  static void quitLoadingLibrary(void);

private:

  SDL_Texture* texture;
  SDL_Surface* surface;
  int sizeX;
  int sizeY;
  static SDL_Renderer* renderer;

};

#endif
