#include "window.h"
#include "image.h"

#include <iostream>
#include <unistd.h>

using namespace std;

int main(void)
{
    Image test0 = Image("data/textures/test0.png");
    Color red = Color(255, 0, 0);
    Window win = Window(100, 100, "Test de Window");

    cout << "Initialisation termine" << endl;

    test0.print();

    win.getScreen()->blit(&test0, 0, 0, 0, 0, test0.getSizeX(), test0.getSizeY());
    win.createWin();
    //win.updateWin();
    sleep(10);
    win.getScreen()->fillColor(red);
    //win.updateWin();
    sleep(5);
    win.getScreen()->blit(&test0, 50, 50, 0, 0, test0.getSizeX(), test0.getSizeY());
    sleep(5);

    return 0;
}
