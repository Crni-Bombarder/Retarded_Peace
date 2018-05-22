#ifndef SPRIT_H
#define SPRIT_H

#include <vector>
#include <map>

#include "image.h"

#define NMB_COLOR 5

class Sprit {
public:
    Sprit();
    Sprit(string _typeUnit);
    ~Sprit();
    Image* getImage(int _owner);

    static Image* getImageUnit(string _typeUnit, int _owner);
private:
    string typeUnit;
    std::vector<Image> listImage;

    static std::map<string, Sprit*> vectorSprit;
};

#endif
