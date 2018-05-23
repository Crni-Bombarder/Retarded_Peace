#ifndef ARTILLERY_H
#define ARTILLERY_H

#include "vehicules.h"

#include <string>

using namespace std;

class Artillery: public Vehicules
{
public:
    Artillery();
    ~Artillery();

    Artillery(string _typeName);
};

#endif
