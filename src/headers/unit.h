#ifndef UNIT_H
#define UNIT_H

#include "rect.h"
#include "map.h"

class Unit{
public:

    Unit();
    Unit(int _PV, int _movePoints, int _idImage, int _idType);
    ~Unit();

    bool move(Rect _dst);
    static void setGameMap(Map* _map);

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

    static Map* gameMap;

};


#endif //UNIT_H
