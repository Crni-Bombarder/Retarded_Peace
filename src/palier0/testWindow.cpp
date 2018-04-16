#include "window.h"
#include "image.h"

#include <cv.hpp>
#include <iostream>

using namespace std;

int main(void)
{
    Image test0 = Image("data/textures/test0.png");
    Color red = Color(255, 0, 0);
    Window win = Window(100, 100, "Test de Window");

    cout << "Initialisation termine" << endl;

    test0.print();

    win.getScreen()->blit(&test0, 1, 1, test0.getSizeX(), test0.getSizeY());
        win.createWin();
    //win.updateWin();
    waitKey(0);
    win.getScreen()->fillColor(red);
    //win.updateWin();
    waitKey(0);
    win.getScreen()->blit(&test0, 50, 50, test0.getSizeX(), test0.getSizeY());
    waitKey(0);

    return 0;
}
