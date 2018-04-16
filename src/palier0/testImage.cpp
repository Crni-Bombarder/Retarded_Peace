#include "../headers/image.h"


int main (int argc, char* argv[])
{
    Image background(2, 2);
    background.print();
    background.resizeImg(3, 2);
    background.print();
    Image object;
    Color color(255, 0, 0, 255);
    object.fillColor(color);
    object.print();
    background.blit(object, 1, 1, 2, 2);
    background.print();
    Color pixel = background.getPixel(1, 2);
    pixel.print();
    return 0;
}
