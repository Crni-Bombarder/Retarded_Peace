#include <iostream>
#include <unistd.h>

#include "unit.h"
#include "genericinfantry.h"
#include "display.h"

int main()
{

    GenericInfantry genericinfantry =  GenericInfantry("infanterie");

    Unit test = Unit("infanterie", 0);

    std::cout << test.getStrType() << std::endl;
    std::cout << test.getMoveMalus("plaine") << std::endl;
    std::cout << test.getOwner() << std::endl;

    VectorImage vectorImage = VectorImage();
    vectorImage.initVector();
    Terrain plaine = Terrain(0, "plaine");
    Terrain eau = Terrain(1, "mer");
    Map map = Map("map0");
    Display display = Display(&map, &vectorImage, 48, 48);
    display.startDisplay();
    vectorImage.loadImage("data/textures/test0.png");
    vectorImage.loadImage("data/textures/test1.png");
    vectorImage.loadImage("data/units/infantery.png");
    map.getTile(5, 5)->setUnit(&test);
    display.updateDisplay();
    sleep(10);
    display.stopDisplay();
    return 0;
}
