#include "headers/image.h"

#define MAT_TYPE CV_8UC4

Image::Image()
{
  sizeX = 0;
  sizeY = 0;
  screen = Mat(0, 0, MAT_TYPE);
}

Image::~Image(){}

void Image::fillColor(Color _color)
{
  screen.setTo(Scalar(_color.getR(), _color.getG(), _color.getB(), _color.getA()));
}

void Image::blit(Image _image, int _x, int _y, int _sizeX, int _sizeY)
{
  Mat* blitMat = new Mat(_sizeX, _sizeY, MAT_TYPE);       // A vérifier pour l'allocation dynamique
  *blitMat = _image.getMat();
  blitMat->copyTo(screen(Rect(_sizeX, _sizeY, _x, _y)));
  delete blitMat;
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
    Vec4b color = screen.at<uchar>(_x, _y);       // Fonction à terminer
}

Mat Image::getMat()
{
  return screen;
}

void Image::resize(int _sizeX, int _sizeY)
{
  resize(screen, screen, Size(_sizeX, _sizeY));
}
