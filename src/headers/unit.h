#ifndef UNIT_H
#define UNIT_H

#include "rect.h"

class Unit{
public:

    Unit();
    ~Unit();

    bool move(Rect _dst);

    int getPV();
    int getIdType();
    int getIdImage();
    void setPV(int _PV);

private:

    int PV;
    Rect position;

protected:

    virtual void initUnit() = 0;

    int movePoints;
    int idImage;
    int idType;

};


#endif //UNIT_H
