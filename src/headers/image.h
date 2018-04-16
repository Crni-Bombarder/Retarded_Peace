#ifndef IMAGE_H
#define IMAGE_H

#include <cv.hpp>
#include "color.h"
#include <string.h>

using namespace cv;

class Image{
public:

  Image();
  Image(int _x, int _y);    //Made an empty image of size x and y
  Image(String _namefile);  //Load the image from a image file
  ~Image();

  void fillColor(Color _color);
  void blit(Image* _image, int _x, int _y, int _sizeX, int _sizeY);
  int getSizeX(void);
  int getSizeY(void);
  Color getPixel(int _x, int _y);
  void resizeImg(int _sizeX, int _sizeY);
  Mat* getMat();   //Return the pointer to the Mat

  void print(void);

private:

  Mat screen;
  int sizeX;
  int sizeY;

};

#endif
