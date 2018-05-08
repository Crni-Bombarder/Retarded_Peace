#include <iostream>

#include "unit.h"
#include "genericinfantry.h"

int main()
{

    GenericInfantry genericinfantry =  GenericInfantry("infanterie");
    
    Unit test = Unit("infanterie", 0);

    std::cout << test.getStrType() << std::endl;
    std::cout << test.getMoveMalus("plaine") << std::endl;
    std::cout << test.getOwner() << std::endl;


    return 0;
}
