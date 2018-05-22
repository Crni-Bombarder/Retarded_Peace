#include "display.h"
#include <unistd.h>

int main (int argc, char* argv[])
{
    VectorImage vectorImage = VectorImage();
    vectorImage.initVector();
    Terrain plaine = Terrain(0, "plaine");
    Terrain eau = Terrain(1, "mer");
    Map map = Map("map0");
    Display display = Display(&map, &vectorImage, 48, 48);
    display.startDisplay();
    vectorImage.loadImage("data/textures/test0.png");
    vectorImage.loadImage("data/textures/test1.png");
    display.updateDisplay();
    sleep(10);
    display.stopDisplay();
    return 0;
}
