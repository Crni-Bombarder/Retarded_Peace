#include "headers/image.h"

SDL_Renderer* Image::renderer = NULL;

Image::Image(){}

Image::Image(int _x, int _y)
{
    sizeX = _x;
    sizeY = _y;
    texture = SDL_CreateTexture(renderer ,SDL_PIXELFORMAT_ARGB8888,
                                SDL_TEXTUREACCESS_STATIC, _x, _y);
    surface = NULL;
}

Image::Image(string _namefile)
{
    texture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(_namefile.c_str());
    if(loadedSurface == NULL)
    {
        cout << "Unable to load image" << _namefile.c_str() << " ! SDL_image Error : " << IMG_GetError() << endl;
        exit(1);
    } else {
        texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if(texture == NULL)
        {
            cout << "Unable to convert the surface" << _namefile.c_str() << " ! SDL_image Error : " << IMG_GetError() << endl;
            exit(1);
        }
        sizeX   = loadedSurface->w;
        sizeY   = loadedSurface->h;
        surface = loadedSurface;
    }
}

Image::~Image(){}

int Image::getSizeX()
{
  return sizeX;
}

int Image::getSizeY()
{
  return sizeY;
}

Color Image::getPixel(int _x, int _y)
{
    if (surface == NULL)
    {
        cout << "Cannot read the pixel of this Texture, because optimisation ! x : " << sizeX << ", y : " << sizeY << endl;
        exit(1);
    }
    SDL_LockSurface(surface);
    SDL_PixelFormat* format = surface->format;
    Uint32* tabPixel = (Uint32*)(surface->pixels);
    int index = (_y*surface->w + _x);
    unsigned int valPixel = (unsigned int)tabPixel[index];
    cout << valPixel << endl;
    Color color = Color(valPixel & 0xFF000000 >> 24,
                        valPixel & 0x00FF0000 >> 16,
                        valPixel & 0x0000FF00 >> 8,
                        valPixel & 0x000000FF);
    SDL_UnlockSurface(surface);
    return color;
}

SDL_Texture* Image::getTexture()
{
  return texture;
}

void Image::print()
{
    std::cout << "Size X : " << sizeX << std::endl;
    std::cout << "Size Y : " << sizeY << std::endl;
}

void Image::initLoadingLibrary(SDL_Renderer* _renderer)
{
    IMG_Init(IMG_INIT_PNG);
    renderer = _renderer;
}

void Image::quitLoadingLibrary(void)
{
    IMG_Quit();
}
