#include "headers/display.h"

Color black = Color(0, 0, 0);

Display::Display()
{
    screenX = 0;
    screenY = 0;
    tileX = 0;
    tileY = 0;
    gameMap = nullptr;
    dispWindow = nullptr;
}

Display::Display(Map* _map, VectorImage* _vectorImage, int _screenX, int _screenY, int _tileX, int _tileY)
{
    screenX = _screenX;
    screenY = _screenY;
    tileX = _tileX;
    tileY = _tileY;
    gameMap = _map;
    dispWindow = nullptr;
    vectorImage = _vectorImage;
}

Display::~Display()
{
    stopDisplay();
}

bool Display::startDisplay()
{
    Window::initVideoDriver();
    dispWindow = new Window(screenX, screenY, "Retarded Peace");
    dispWindow->createWin();
}

bool Display::stopDisplay()
{
    dispWindow->destroyWin();
    delete dispWindow;
    Window::quitVideoDriver();
}

bool Display::updateDisplay()
{
    Image* image;
    int nmbTilesX = gameMap->getNmbTilesX();
    int nmbTilesY = gameMap->getNmbTilesY();
    Rect dst = Rect(0, 0, tileX, tileY);
    dispWindow->clearWin(black);
    for (int i = 0; i < nmbTilesY; i++) {
        for (int j = 0; j < nmbTilesX; j++) {
            image = vectorImage->getImageFromIndex(gameMap->getTerrainFromTiles(i, j)->getIdImage());
            dispWindow->blitImage(image, NULL, &dst);
            dst.setX(dst.getX() + tileX);
        }
        dst.setX(0);
        dst.setY(dst.getY() + tileY);
    }
    dispWindow->updateWin();
}
