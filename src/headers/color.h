#ifndef COLOR_H
#define COLOR_H

#include <iostream>

class Color{

public:

  Color();
  Color(unsigned int _r, unsigned int _g, unsigned int _b);
  Color(unsigned int _r, unsigned int _g, unsigned int _b, unsigned int _a);
  ~Color();

  unsigned int getR();
  unsigned int getG();
  unsigned int getB();
  unsigned int getA();
  unsigned int getRGBA();

  void setR(unsigned int _r);
  void setG(unsigned int _g);
  void setB(unsigned int _b);
  void setA(unsigned int _a);

  void print(void);

private:

  unsigned int r;
  unsigned int g;
  unsigned int b;
  unsigned int a;

};

#endif
