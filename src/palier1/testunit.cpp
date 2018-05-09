#include <iostream>
#include <unistd.h>

#include "unit.h"
#include "genericinfantry.h"
#include "display.h"
#include "rect.h"

using namespace std;

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
    vectorImage.loadImage("data/textures/cursor.png");
    vectorImage.loadImage("data/textures/highlight.png");
    display.enableCursor();
    display.setCursorPosition(Rect(5, 5));
    map.getTile(5, 5)->setUnit(&test);
    std::vector<Rect> vec = std::vector<Rect>();
    vec.push_back(Rect(5,5));
    vec.push_back(Rect(6,5));
    vec.push_back(Rect(4,5));
    vec.push_back(Rect(5,4));
    vec.push_back(Rect(5,6));
    cout << vec.size() << endl;
    display.updateVectorHighlight(vec, BLUE);
    cout << "Update highlight" << endl;
    display.updateDisplay();
    sleep(10);
    display.stopDisplay();
    return 0;
}
