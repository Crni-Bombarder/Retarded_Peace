#include "headers/window.h"


Window::Window()
{
    screenX = 0;
    screenY = 0;
    winMutex = NULL;
}

Window::~Window()
{
    winMutex = NULL;
}

bool Window::createWin()
{

    namedWindow(windowName, WINDOW_AUTOSIZE);
    imshow(windowName, *screen.getMat());
}

bool Window::destroyWin()
{
    destroyWindow(windowName);
}

void Window::updateWin()
{

}

Image* Window::getScreen()
{
    return
}

