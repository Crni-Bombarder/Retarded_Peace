#include "headers/window.h"

using namespace std;

Window::Window(){}

Window::Window(unsigned int _screenX, unsigned int _screenY)
{
    screenX = _screenX;
    screenY = _screenY;
    window = NULL;
    renderer = NULL;
    windowName = "Retarded Peace";
}

Window::Window(unsigned int _screenX, unsigned int _screenY, string _windowName)
{
    screenX = _screenX;
    screenY = _screenY;
    window = NULL;
    renderer = NULL;
    windowName = _windowName;
}

Window::~Window()
{
    if (window != NULL || renderer != NULL)
        destroyWin();
}

bool Window::createWin()
{
    window = SDL_CreateWindow(windowName.c_str(),
                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenX, screenY, 0);
    if (window == NULL)
    {
        cout << "Cannot create the window " << windowName << " ! Error : " << SDL_GetError() << endl;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL)
    {
        cout << "Cannot create the renderer of " << windowName << " ! Error : " << SDL_GetError() << endl;
    }

    Image::initLoadingLibrary(renderer);
}

bool Window::destroyWin()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    Image::quitLoadingLibrary();
}

void Window::updateWin()
{
    SDL_RenderPresent(renderer);
}

void Window::blitImage(Image* _image, Rect* src, Rect* dst)
{
    SDL_Rect* psrcrect;
    SDL_Rect* pdstrect;

    if (src == NULL)
    {
        psrcrect = NULL;
    } else {
        SDL_Rect srcrect = {src->getX(), src->getY(), src->getW(), src->getH()};
        psrcrect = & srcrect;
    }

    if (dst == NULL)
    {
        pdstrect = NULL;
    } else {
        SDL_Rect dstrect = {dst->getX(), dst->getY(), dst->getW(), dst->getH()};
        pdstrect = &dstrect;
    }

    SDL_RenderCopy(renderer, _image->getTexture(), psrcrect, pdstrect);
}


void Window::clearWin(Color color)
{
    SDL_SetRenderDrawColor(renderer, color.getR(), color.getG(),
                                  color.getB(), color.getA());
    SDL_RenderClear(renderer);
}

void Window::initVideoDriver(void)
{
  SDL_Init(SDL_INIT_VIDEO);
}

void Window::quitVideoDriver(void)
{
  SDL_Quit();
}
