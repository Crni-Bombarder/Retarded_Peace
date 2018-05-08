#ifndef UNIT_H
#define UNIT_H

#include <string>

#include "rect.h"
#include "typeunit.h"

class Unit{
public:

    Unit();
    ~Unit();

    void move(Rect _dst);

    int getPV();
    String getStrType();
    int getIdImage();
    int getMoveMalus(String strTerrain);
    int getMovePoint();
    Rect getPosition();
    int getOwner();
    bool hasMoved();
    void setPV(int _PV);

private:

    int PV;
    Rect position;
    int owner;

    bool moved;
    String strType;

};


#endif //UNIT_H
