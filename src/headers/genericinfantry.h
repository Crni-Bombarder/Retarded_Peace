#ifndef GENERICINFANTRY_H
#define GENERICINFANTRY_H

#include <string>

using namespace std;

class GenericInfantry : public TypeUnit{
public:
    GenericInfantry();
    ~GenericInfantry();

    GenericInfantry(string _typeName);
};

GenericInfantry genericinfantery =  GenericInfantry("infanterie");

#endif
