#include "../headers/image.h"
#include "../headers/window.h"

#include <unistd.h>


int main (int argc, char* argv[])
{
    Window::initVideoDriver();
    Window win = Window(800, 600, "Test Image and Window");
    win.createWin();
    Image background("data/textures/test0.png");
    background.print();
    //Color pixel = background.getPixel(1, 2);
    //pixel.print();

    win.destroyWin();
    Window::quitVideoDriver();

    return 0;
}
