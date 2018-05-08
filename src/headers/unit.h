#ifndef UNIT_H
#define UNIT_H

#include <string>

#include "rect.h"
#include "typeunit.h"

using namespace std;

class Unit{
public:

    Unit();
    Unit(string _strType, int _owner=0);
    ~Unit();

    void move(Rect _dst);

    int getPV();
    string getStrType();
    int getIdImage();
    int getMoveMalus(string strTerrain);
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
    string strType;

};


#endif //UNIT_H
