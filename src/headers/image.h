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
  Image(SDL_Surface* _surface);
  ~Image();

  void fillColor(Color _color);
  void blit(Image* _image, int _dstX, int _dstY, int _srcX, int _srcY, int _sizeX, int _sizeY);
  int getSizeX(void);
  int getSizeY(void);
  Color getPixel(int _x, int _y);
  //void resizeImg(int _sizeX, int _sizeY);
  SDL_Surface* getSurface();   //Return the pointer to the SDL_Surface

  void print(void);

private:

  SDL_Surface* screen;
  int sizeX;
  int sizeY;
  static SDL_PixelFormat* format;

  static void initImageLoad(SDL_PixelFormat* _format);

};

#endif
