#ifndef GENERICARTILLERY_H
#define GENERICARTILLERY_H

#include "typeunit.h"

#include <string>

using namespace std;

class GenericArtillery: public TypeUnit
{
public:
    GenericArtillery();
    ~GenericArtillery();

    GenericArtillery(string _typeName);
};

#endif
