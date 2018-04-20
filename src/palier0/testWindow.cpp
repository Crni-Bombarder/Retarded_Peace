#include "window.h"
#include "image.h"
#include "rect.h"

#include <iostream>
#include <unistd.h>

using namespace std;

int main(void)
{
    Window::initVideoDriver();
    Window win = Window(800, 600, "Test Window");
    win.createWin();

    Image test0 = Image("data/textures/test0.png");

    Rect dst = Rect(0,0, test0.getSizeX(), test0.getSizeY());
    Color black = Color(255, 0, 0);

    win.clearWin(black);
    win.blitImage(&test0, NULL, NULL);
    win.updateWin();

    sleep(10);

    win.destroyWin();

    Window::quitVideoDriver();

    return 0;
}
