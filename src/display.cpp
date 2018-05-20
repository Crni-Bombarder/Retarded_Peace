#include "headers/display.h"

Color black = Color(0, 0, 0);

Display::Display()
{
    screenX = 0;
    screenY = 0;
    tileX = 0;
    tileY = 0;

    posCursor = Rect(0,0);
    dispCursor = false;

    gameMap = nullptr;
    dispWindow = nullptr;
    vectorImage = nullptr;
}

Display::Display(Map* _map, VectorImage* _vectorImage, int _screenX, int _screenY, int _tileX, int _tileY)
{
    screenX = _screenX;
    screenY = _screenY;
    tileX = _tileX;
    tileY = _tileY;

    posCursor = Rect(0,0);
    dispCursor = false;

    gameMap = _map;
    dispWindow = nullptr;
    vectorImage = _vectorImage;
}

Display::Display(Map* _map, VectorImage* _vectorImage, int _tileX, int _tileY)
{
    gameMap = _map;
    tileX = _tileX;
    tileY = _tileY;
    screenX = tileX*gameMap->getNmbTilesX();
    screenY = tileY*gameMap->getNmbTilesY();

    posCursor = Rect(0,0);
    dispCursor = false;

    dispWindow = nullptr;
    vectorImage = _vectorImage;
}

Display::~Display()
{
}

void Display::enableCursor()
{
    dispCursor = true;
}

void Display::disableCursor()
{
    dispCursor = false;
}

bool Display::getCursorStatut()
{
    return dispCursor;
}

void Display::setCursorPosition(Rect _position)
{
    posCursor = _position;
}

Rect Display::getCursorPosition()
{
    return posCursor;
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
    cout << "Window closed" << endl;
    delete dispWindow;
    cout << "Window deleted" << endl;
    Window::quitVideoDriver();
    cout << "Video Driver quit" << endl;
}

bool Display::updateDisplay()
{
    Image* image;
    Unit* unit;
    CaseHighlight valHighlight;
    int nmbTilesX = gameMap->getNmbTilesX();
    int nmbTilesY = gameMap->getNmbTilesY();
    Rect dst = Rect(0, 0, tileX, tileY);
    dispWindow->clearWin(black);

    //Map display
    for (int y = 0; y < nmbTilesY; y++) {
        for (int x = 0; x < nmbTilesX; x++) {

            //Terrain display
            image = vectorImage->getImageFromIndex(gameMap->getTerrainFromTiles(x, y)->getIdImage());
            dispWindow->blitImage(image, NULL, &dst);
            unit = gameMap->getUnitFromTiles(x, y);

            //Unit display
            if (unit != nullptr)
            {
                image = vectorImage->getImageFromIndex(unit->getIdImage());
                dispWindow->blitImage(image, NULL, &dst);
                if (unit->hasMoved())
                {
                    dispWindow->blitImage(vectorImage->getImageFromIndex(GREY_IMAGE_ID), NULL, &dst);
                }
            }

            //Highlight display
            valHighlight = gameMap->getVectorHighlight()[y*nmbTilesX + x] == BLUE;
            if (valHighlight)
            {
                image = vectorImage->getImageFromIndex(BLUE_IMAGE_ID);
                dispWindow->blitImage(image, NULL, &dst);
            } else if
            {
                image = vectorImage->getImageFromIndex(RED_IMAGE_ID);
                dispWindow->blitImage(image, NULL, &dst);
            }

            dst.setX(dst.getX() + tileX);
        }
        dst.setX(0);
        dst.setY(dst.getY() + tileY);
    }

    //Cursor display
    if (dispCursor)
    {
        image = vectorImage->getImageFromIndex(CURSOR_IMAGE_ID);
        dst.setX(posCursor.getX()*tileX);
        dst.setY(posCursor.getY()*tileY);
    }

    dispWindow->blitImage(image, NULL, &dst);
    dispWindow->updateWin();
}

bool Display::resizeWindow()
{
    return dispWindow->resizeWindow(tileX*gameMap->getNmbTilesX(), tileY*gameMap->getNmbTilesY());
}
