#include "rect.h"

Rect::Rect()
{
    x = 0;
    y = 0;
    w = 0;
    h = 0;
}

Rect::Rect(int _x, int _y)
{
    x = _x;
    y = _y;
    w = 0;
    h = 0;
}

Rect::Rect(int _x, int _y, int _w, int _h)
{
    x = _x;
    y = _y;
    w = _w;
    h = _h;
}

Rect::~Rect() {}

int Rect::getX()
{
    return x;
}
int Rect::getY()
{
    return y;
}
int Rect::getW()
{
    return w;
}
int Rect::getH()
{
    return h;
}

void Rect::setX(int _x)
{
    x = _x;
}
void Rect::setY(int _y)
{
    y = _y;
}
void Rect::setW(int _w)
{
    w = _w;
}
void Rect::setH(int _h)
{
    h = _h;
}
