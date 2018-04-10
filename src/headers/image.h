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

  void fillColor(Color _color);
  void blit(Image _image, int _x, int _y, int _sizeX, int _sizeY);
  int getSizeX(void);
  int getSizeY(void);
  Color getPixel(int _x, int _y);
  Mat getMat();
  void resize(int _sizeX, int _sizeY);

private:

  Mat screen;
  int sizeX;
  int sizeY;

};

#endif
