#include "color.h"

Color::Color()
{
    r = 0;
    g = 0;
    b = 0;
    a = 255;
}

Color::Color(unsigned int _r, unsigned int _g, unsigned int _b)
{
  r = _r;
  g = _g;
  b = _b;
  a = 255;
}

Color::Color(unsigned int _r, unsigned int _g, unsigned int _b, unsigned int _a)
{
  r = _r;
  g = _g;
  b = _b;
  a = _a;
}

Color::~Color(){}

unsigned int Color::getR(){ return r; }
unsigned int Color::getG(){ return g; }
unsigned int Color::getB(){ return b; }
unsigned int Color::getA(){ return a; }
unsigned int Color::getRGBA(){ return a | b << 8 | g << 16 | r << 24; }

void Color::setR(unsigned int _r){ r = _r%256; }
void Color::setG(unsigned int _g){ g = _g%256; }
void Color::setB(unsigned int _b){ b = _b%256; }
void Color::setA(unsigned int _a){ a = _a%256; }

void Color::print(void)
{
  std::cout << r << " " << g << " " << b << " " << a << std::endl;
}
