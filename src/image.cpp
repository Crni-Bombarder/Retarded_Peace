#include "headers/image.h"


#define MAT_TYPE CV_8UC4

Image::Image()
{
  sizeX = 1;
  sizeY = 1;
  screen = Mat(1, 1, MAT_TYPE);
}

Image::Image(int _x, int _y)
{
    sizeX = _x;
    sizeY = _y;
    screen = Mat(_x, _y, MAT_TYPE);
}



Image::~Image(){}

void Image::fillColor(Color _color)
{
  screen.setTo(Scalar(_color.getR(), _color.getG(), _color.getB(), _color.getA()));
}

void Image::blit(Image _image, int _x, int _y, int _sizeX, int _sizeY)
{
  Mat* blitMat;
  blitMat = _image.getMat();
  resize(*blitMat, *blitMat, Size(_sizeX, _sizeY));
  blitMat->copyTo(screen(Rect(_x - 1, _y - 1, _sizeX, _sizeY)));
}

int Image::getSizeX(void)
{
  return sizeX;
}

int Image::getSizeY(void)
{
  return sizeY;
}

Color Image::getPixel(int _x, int _y)
{
    Vec4b getColors = screen.at<uchar>(_x, _y);
    Color colors(getColors[0], getColors[1], getColors[2], getColors[3]);
    return colors;
}

Mat* Image::getMat()
{
  return &screen;
}

void Image::resizeImg(int _sizeX, int _sizeY)
{
  resize(screen, screen, Size(_sizeX, _sizeY));
  sizeX = _sizeX;
  sizeY = _sizeY;
}

void Image::print(void)
{
    std::cout << "Size X : " << sizeX << std::endl;
    std::cout << "Size Y : " << sizeY << std::endl;
    std::cout << "Mat : " << screen << std::endl;
}