#ifndef RECT_H
#define RECT_H

class Rect {
public:
    Rect();
    Rect(int _x, int _y);
    Rect(int _x, int _y, int _w, int _h);
    ~Rect();

    Rect operator=(const Rect &other);
    bool operator==(const Rect &other);

    int getX() const;
    int getY() const;
    int getW() const;
    int getH() const;

    void setX(int _x);
    void setY(int _y);
    void setW(int _w);
    void setH(int _h);

private:
    int x;
    int y;
    int w;
    int h;
};

#endif
