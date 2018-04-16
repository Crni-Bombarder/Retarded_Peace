#include "headers/window.h"


Window::Window(){}

Window::Window(unsigned int _screenX, unsigned int _screenY)
{
    screenX = _screenX;
    screenY = _screenY;
    screen = Image(_screenX, _screenY);
    windowName = "Retarded Peace";
}

Window::Window(unsigned int _screenX, unsigned int _screenY, String _windowName)
{
    screenX = _screenX;
    screenY = _screenY;
    screen = Image(_screenX, _screenY);
    windowName = _windowName;
}

Window::~Window()
{
    destroyWin();
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
    updateWindow(windowName);
}

Image* Window::getScreen()
{
    return &screen;
}
