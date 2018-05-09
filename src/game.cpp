#include "game.h"

using namespace std;

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
    gameDisplay.resizeWindow();
}

void Game::initGame(void)
{
    gameDisplay.startDisplay();

    libImages.initVector();
    libImages.loadImage("data/textures/test0.png");
    libImages.loadImage("data/textures/test1.png");
    libImages.loadImage("data/units/infantery.png");
    //libImages.loadImage("data/textures/test1.png");

    new Terrain(0, "plaine");
    new Terrain(1, "mer");
}

bool Game::StartGame(void)
{
    gameRunning = true;
    //gameThread = new thread(&Game::loop, this);
    loop();
}

bool Game::StopGame(void)
{
    gameRunning = false;
    //gameThread->join();
    //delete gameThread;
}

void Game::getAllowedMoves(Unit* unit, vector<Rect>* allowedMoves)
{
  int nmbMovePoints = getTypeUnit(unit->getStrType())->getMovePoints();
  int tabSize = (nmbMovePoints*2 + 1);
  vector<vector<int>> moves = vector<vector<int>>(tabSize, vector<int>(tabSize));
  for(int i = 0; i < tabSize - 1; i++)
  {
    for(int j = 0; j < tabSize - 1; i++)
    {
          moves[i][j] = 0;
    }
  }

}

void Game::loop()
{
    SDL_Event event;
    clock_t t;
    while (gameRunning == true)
    {
        t = clock();
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_WINDOWEVENT)
            {
                if (event.window.event == SDL_WINDOWEVENT_CLOSE)
                {
                    gameRunning = false;
                }
            }
        }

        gameDisplay.updateDisplay();

        t = clock() - t;

        usleep((unsigned int)((1.0/FRAMERATE-(double)t/CLOCKS_PER_SEC)*1000000));
    }
}
