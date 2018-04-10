#ifndef IMAGE_H
#define IMAGE_H

#include <cv.h>
#include <highgui.h>
#include "color.h"
#include "mat.h"

class Image{
public:

  Image();
  ~Image();

  void fillColor(Color);
  void blit(Image, int x, int y, int sizeX, int sizeY);
  int getSizeX(void);
  int getSizeY(void);
  Color getPixel(int x, int y);
  bool resize(int sizeX, int sizeY);

private:

  Mat screen;
  int sizeX;
  int sizeY;

};

#endif
