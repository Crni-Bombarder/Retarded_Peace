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

Rect Rect::operator=(const Rect &other)
{
    if (this != &other)
    {
        this->x = other.getX();
        this->y = other.getY();
        this->w = other.getW();
        this->h = other.getH();
    }
    return *this;
}

bool Rect::operator==(const Rect &other)
{
    return (this->x == other.getX()
            && this->y == other.getY()
            && this->w == other.getW()
            && this->h == other.getH());
}

int Rect::getX() const
{
    return x;
}
int Rect::getY() const
{
    return y;
}
int Rect::getW() const
{
    return w;
}
int Rect::getH() const
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
