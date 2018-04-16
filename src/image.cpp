#include "headers/image.h"

Image::Image(){}

Image::Image(int _x, int _y)
{
    sizeX = _x;
    sizeY = _y;
    screen = SDL_CreateRGBSurface(0, _x, _y, 32, 0, 0, 0, 0);
    if (screen == NULL)
    {
        SDL_Log("SDL_CreateRGBSurface() failed: %s", SDL_GetError());
        exit(1);
    }
}

Image::Image(string _namefile)
{
    screen = NULL;
    SDL_Surface* loadedSurface = IMG_Load(_namefile.c_str());
    if(loadedSurface == NULL)
    {
        cout << "Unable to load image" << _namefile.c_str() << " ! SDL_image Error : " << IMG_GetError() << endl;
        exit(1);
    } else {
        screen = SDL_ConvertSurface(loadedSurface, format, NULL);
        if(screen == NULL)
        {
            cout << "Unable to optimize image" << _namefile.c_str() << " ! SDL Error : " << SDL_GetError() << endl;
            exit(1);
        }
        SDL_FreeSurface(loadedSurface);
        sizeX = screen->w;
        sizeY = screen->h;
    }
}

Image::Image(SDL_Surface* _surface)
{
    screen = _surface;
    sizeX = screen->w;
    sizeY = screen->h;
    initImageLoad(screen->format);
}

Image::~Image(){}

void Image::fillColor(Color _color)
{
  SDL_FillRect(screen, 0, _color.getRGBA());
}

void Image::blit(Image* _image, int _dstX, int _dstY, int _srcX, int _srcY, int _sizeX, int _sizeY)
{
    SDL_Rect dstRect = {_dstX, _dstY, 0, 0};
    SDL_Rect srcRect = {_srcX, _srcY, _sizeX, _sizeY};
    SDL_BlitSurface(_image->getSurface(), &srcRect, screen, &dstRect);
}

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
    SDL_LockSurface(screen);
    Uint8* tabPixel = (Uint8*)(screen->pixels);
    int index = (_y*getSizeY() + _x)*format->BytesPerPixel;
    Color color = Color((unsigned int)(tabPixel[index] & format->Rmask >> format->Rshift << format->Rloss),
                        (unsigned int)(tabPixel[index] & format->Gmask >> format->Gshift << format->Gloss),
                        (unsigned int)(tabPixel[index] & format->Bmask >> format->Bshift << format->Bloss),
                        (unsigned int)(tabPixel[index] & format->Amask >> format->Ashift << format->Aloss));
    SDL_UnlockSurface(screen);
    return color;
}

SDL_Surface* Image::getSurface()
{
  return screen;
}

/*void Image::resizeImg(int _sizeX, int _sizeY)
{

  sizeX = _sizeX;
  sizeY = _sizeY;
}*/

void Image::print()
{
    std::cout << "Size X : " << sizeX << std::endl;
    std::cout << "Size Y : " << sizeY << std::endl;
    std::cout << "Surface : " << screen << std::endl;
}

void Image::initImageLoad(SDL_PixelFormat* _format)
{
    format = _format;
}