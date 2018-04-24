#ifndef UNIT_H
#define UNIT_H

#include "rect.h"

class Unit{
public:

    Unit();
    Unit(int _PV, int _movePoints, int _idImage, int _idType);
    ~Unit();

    bool move(Rect _dst);

    int getPV();
    int getIdType();
    int getIdImage();
    void setPV(int _PV);

private:

    int PV;
    int movePoints;
    int idImage;
    int idType;

    Rect position;

};


#endif //UNIT_H
