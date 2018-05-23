#include "editor.h"

using namespace std;

Editor::Editor() {}

Editor::Editor(string _mapFile)
{
    new Player();
    new Player();
    new Player();
    new Player();
    new Player();

    gameMap = Map(_mapFile);
    mapFile = _mapFile;
    libImages = VectorImage();
    gameDisplay = Display(&gameMap, &libImages, 20, 20, 32, 32);
    gameRunning = false;
}

Editor::Editor(int _nmbTilesX, int _nmbTilesY, string _mapFile)
{
    new Player();
    new Player();
    new Player();
    new Player();
    new Player();

    gameMap = Map(_nmbTilesX, _nmbTilesY, _mapFile);
    mapFile = _mapFile;
    libImages = VectorImage();
    gameDisplay = Display(&gameMap, &libImages, 20, 20, 32, 32);
    gameRunning = false;
}

Editor::~Editor() {}

void Editor::loop()
{
    int movespeed = MOVE_SPEED_CURSOR;
    unsigned int waitingTime;
    Rect cursorPosition = Rect(0, 0);

    bool placeUnit = false;
    auto mapTerrain = Terrain::getMapTerrain();
    auto mapTypeUnit = TypeUnit::getMapTypeUnit();

    auto terrainIterator = mapTerrain.begin();
    auto typeUnitIterator = mapTypeUnit.begin();

    int currentPlayer = 0;

    SDL_Event event;
    clock_t t;

    gameDisplay.enableCursor();
    gameDisplay.updateDisplay();

    cout << "Editor running !" << endl;

    while (gameRunning == true)
    {
        t = clock();

        cursorPosition = gameDisplay.getCursorPosition();

        while(SDL_PollEvent(&event))
        {
            cursorPosition = gameDisplay.getCursorPosition();

            if (event.type == SDL_WINDOWEVENT)
            {
                if (event.window.event == SDL_WINDOWEVENT_CLOSE)
                {
                    gameRunning = false;
                }
            }

            if (event.type == SDL_KEYDOWN)
            {
                if (movespeed == 0)
                {
                    if (event.key.keysym.sym == SDLK_LEFT)
                    {
                        cursorLeft();
                        movespeed = MOVE_SPEED_CURSOR;
                    }
                    if (event.key.keysym.sym == SDLK_RIGHT)
                    {
                        cursorRight();
                        movespeed = MOVE_SPEED_CURSOR;
                    }
                    if (event.key.keysym.sym == SDLK_UP)
                    {
                        cursorUp();
                        movespeed = MOVE_SPEED_CURSOR;
                    }
                    if (event.key.keysym.sym == SDLK_DOWN)
                    {
                        cursorDown();
                        movespeed = MOVE_SPEED_CURSOR;
                    }

                    if (event.key.keysym.sym == SDLK_SPACE)
                    {
                        if (placeUnit)
                        {
                            cout << typeUnitIterator->first << endl;
                        } else {
                            gameMap.getTile(cursorPosition)->setNameTerrain(terrainIterator->first);
                        }
                        movespeed = MOVE_SPEED_CURSOR;
                    }

                    if (event.key.keysym.sym == SDLK_u)
                    {
                        if (placeUnit)
                        {
                            typeUnitIterator++;
                            if (typeUnitIterator == mapTypeUnit.end())
                                typeUnitIterator = mapTypeUnit.begin();
                            cout << typeUnitIterator->first << endl;
                        } else {
                            terrainIterator++;
                            if (terrainIterator == mapTerrain.end())
                                terrainIterator = mapTerrain.begin();
                            cout << terrainIterator->first << endl;
                        }
                        movespeed = MOVE_SPEED_CURSOR;
                    }

                    if (event.key.keysym.sym == SDLK_j)
                    {
                        if (placeUnit)
                        {
                            if (typeUnitIterator == mapTypeUnit.begin())
                            {
                                typeUnitIterator = mapTypeUnit.end();
                            }
                            typeUnitIterator--;
                            cout << typeUnitIterator->first << endl;
                        } else {
                            if (terrainIterator == mapTerrain.begin())
                            {
                                terrainIterator = mapTerrain.end();
                            }
                            terrainIterator--;
                            cout << terrainIterator->first << endl;
                        }
                        movespeed = MOVE_SPEED_CURSOR;
                    }

                    if (event.key.keysym.sym == SDLK_t)
                    {
                        placeUnit = !placeUnit;
                        if (placeUnit)
                        {
                            cout << "Placement d'unitées" << endl;
                        } else {
                            cout << "Placement du terrain" << endl;
                        }
                        movespeed = MOVE_SPEED_CURSOR;
                    }
                }
            }
        }

        gameDisplay.updateDisplay();

        if (movespeed != 0) movespeed--;

        t = clock() - t;

        waitingTime = (unsigned int)((1.0/FRAMERATE-(double)t/CLOCKS_PER_SEC)*1000000);
        if (waitingTime > 1000000/FRAMERATE) waitingTime = 0;

        if (waitingTime > 0)
        {
            usleep(waitingTime);
        }
    }
}
