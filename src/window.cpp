#include "headers/window.h"


Window::Window(){}

Window::Window(unsigned int _screenX, unsigned int _screenY)
{
    screenX = _screenX;
    screenY = _screenY;
    screen = NULL;
    windowName = "Retarded Peace";
}

Window::Window(unsigned int _screenX, unsigned int _screenY, string _windowName)
{
    screenX = _screenX;
    screenY = _screenY;
    screen = NULL;
    windowName = _windowName;
}

Window::~Window()
{
    destroyWin();
}

bool Window::createWin()
{
    SDL_Init(0);
    SDL_Surface* screenSurface;
    screenSurface = SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenX, screenY, 0);
    screen = new Image(screenSurface);
}

bool Window::destroyWin()
{
    SDL_Quit();
}

void Window::updateWin()
{
    SDL_Flip(screen->getSurface());
}

Image* Window::getScreen()
{
    return screen;
}
