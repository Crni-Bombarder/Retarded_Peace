#include "headers/display.h"

Color black = Color(0, 0, 0);

Display::Display()
{
    tileScreenX = 0;
    tileScreenY = 0;
    sizeTileX = 0;
    sizeTileY = 0;

    posCursor = Rect(0,0);
    dispCursor = false;

    gameMap = nullptr;
    dispWindow = nullptr;
    vectorImage = nullptr;
}

Display::Display(Map* _map, VectorImage* _vectorImage, int _tileScreenX, int _tileScreenY,
    int _sizeTileX, int _sizeTileY)
{
    tileScreenX = _tileScreenX;
    tileScreenY = _tileScreenY;
    sizeTileX = _sizeTileX;
    sizeTileY = _sizeTileY;

    posCursor = Rect(0,0);
    posScreen = Rect(0,0);
    dispCursor = false;

    gameMap = _map;
    dispWindow = nullptr;
    vectorImage = _vectorImage;
}

Display::Display(Map* _map, VectorImage* _vectorImage, int _sizeTileX, int _sizeTileY)
{
    tileScreenX = _map->getNmbTilesX();
    tileScreenY = _map->getNmbTilesY();
    sizeTileX = _sizeTileX;
    sizeTileY = _sizeTileY;

    posCursor = Rect(0,0);
    posScreen = Rect(0,0);
    dispCursor = false;


    gameMap = _map;
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

void Display::setScreenPosition(Rect _position)
{
    posScreen = _position;
}

Rect Display::getCursorPosition()
{
    return posCursor;
}


Rect Display::getScreenPosition()
{
    return posScreen;
}

void Display::moveLeft()
{
    posScreen.setX(posScreen.getX() - 1);
}
void Display::moveRight()
{
    posScreen.setX(posScreen.getX() + 1);
}
void Display::moveUp()
{
    posScreen.setY(posScreen.getY() - 1);
}
void Display::moveDown()
{
    posScreen.setY(posScreen.getY() + 1);
}

int Display::getTileScreenX()
{
    return tileScreenX;
}
int Display::getTileScreenY()
{
    return tileScreenY;
}

bool Display::startDisplay()
{
    Window::initVideoDriver();
    dispWindow = new Window(tileScreenX*sizeTileX, tileScreenY*sizeTileY, "Retarded Peace");
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
    Rect dst = Rect(0, 0, sizeTileX, sizeTileY);
    dispWindow->clearWin(black);

    if (tileScreenX >= nmbTilesX)
        posScreen.setX((nmbTilesX - tileScreenX)/2);
    if (tileScreenY >= nmbTilesY)
        posScreen.setY((nmbTilesY - tileScreenY)/2);

    //Map display
    for (int y = posScreen.getY(); y < posScreen.getY() + tileScreenY; y++) {
        for (int x = posScreen.getX(); x < posScreen.getX() + tileScreenX; x++) {
            if (x >= 0 && y >= 0 && x < nmbTilesX && y < nmbTilesY)
            {

                //Terrain display
                image = vectorImage->getImageFromIndex(gameMap->getTerrainFromTiles(x, y)->getIdImage());
                dispWindow->blitImage(image, NULL, &dst);
                unit = gameMap->getUnitFromTiles(x, y);

                //Unit display
                if (unit != nullptr)
                {
                    image = Sprit::getImageUnit(unit->getStrType(), unit->getOwner());
                    dispWindow->blitImage(image, NULL, &dst);
                    if (unit->hasMoved())
                    {
                        dispWindow->blitImage(vectorImage->getImageFromIndex(GREY_IMAGE_ID), NULL, &dst);
                    }
                }

                //Highlight display
                valHighlight = gameMap->getVectorHighlight()[y*nmbTilesX + x];
                if (valHighlight == BLUE)
                {
                    image = vectorImage->getImageFromIndex(BLUE_IMAGE_ID);
                    dispWindow->blitImage(image, NULL, &dst);
                } else if (valHighlight == RED)
                {
                    image = vectorImage->getImageFromIndex(RED_IMAGE_ID);
                    dispWindow->blitImage(image, NULL, &dst);
                }
            }

            dst.setX(dst.getX() + sizeTileX);
        }
        dst.setX(0);
        dst.setY(dst.getY() + sizeTileY);
    }

    //Cursor display
    if (dispCursor)
    {
        image = vectorImage->getImageFromIndex(CURSOR_IMAGE_ID);
        dst.setX((posCursor.getX()-posScreen.getX())*sizeTileX);
        dst.setY((posCursor.getY()-posScreen.getY())*sizeTileY);
    }

    dispWindow->blitImage(image, NULL, &dst);
    dispWindow->updateWin();
}

bool Display::resizeWindow()
{
    return dispWindow->resizeWindow(sizeTileX*gameMap->getNmbTilesX(), sizeTileY*gameMap->getNmbTilesY());
}
