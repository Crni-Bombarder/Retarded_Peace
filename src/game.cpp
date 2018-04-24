#include "game.h"

Game::Game()
{

}

Game::Game(string _mapFile)
{
    gameMap = Map(_mapFile);
    mapFile = _mapFile;
    libImages = VectorImage();
    gameDisplay = Display(&gameMap, &libImages, 32, 32);
    gameRunning = false;
}

Game::~Game()
{

}

void Game::setMapFile(string _mapFile)
{
    mapFile = _mapFile;
    gameMap = Map(mapFile);
}

void Game::initGame(void)
{
    gameDisplay.startDisplay();

    libImages.initVector();
    libImages.loadImage("data/textures/test0.png");
    libImages.loadImage("data/textures/test1.png");
    libImages.loadImage("data/units/infantery.png");
    //libImages.loadImage("data/textures/test1.png");

    new Terrain(0);
    new Terrain(1);
}

bool Game::StartGame(void)
{
    gameRunning = true;
    gameThread = new thread(&Game::loop, this);
}

bool Game::StopGame(void)
{
    gameRunning = false;
    gameThread->join();
    delete gameThread;
}

void Game::loop()
{
    clock_t t;
    while (gameRunning == true)
    {
        t = clock();

        gameDisplay.updateDisplay();

        t = clock() - t;
        //cout << t << endl;
        usleep((unsigned int)((1.0/FRAMERATE-(double)t/CLOCKS_PER_SEC)*1000000));
    }
}
