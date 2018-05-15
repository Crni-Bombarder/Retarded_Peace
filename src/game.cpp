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
  int i, j;
  int nmbMovePoints = TypeUnit::getTypeUnit(unit->getStrType())->getMovePoints();
  int tabSize = (nmbMovePoints*2 + 1);
  vector<vector<int>> moves = vector<vector<int>>(tabSize, vector<int>(tabSize));
  for(i = 0; i < tabSize - 1; i++)
  {
    for(j = 0; j < tabSize - 1; i++)
    {
          moves[i][j] = 0;
    }
  }
  verifMoves(unit->getPosition(), 1, tabSize/2 + 1, tabSize/2 + 1, &nmbMovePoints, nmbMovePoints, unit, &moves);
  for (i = 0; i < tabSize - 1; i++)
  {
    for(j = 0; j < tabSize - 1; j++)
    {
      if(moves[i][j] > 0)
      {
        Rect addRect = Rect(unit->getPosition().getX() - (tabSize/2 - i), unit->getPosition().getY() - (tabSize/2 - j), unit->getPosition().getW(), unit->getPosition().getH());
        allowedMoves->push_back(addRect);
      }
    }
  }
}

void Game::loop()
{
    cout << "Create dummy unit" << endl;
    vector<Rect> moves = vector<Rect>();

    SDL_Event event;
    clock_t t;

    Unit unit0("infanterie");
    Rect position(5, 5);
    unit0.setPosition(position);
    gameMap.getTile(position.getX(), position.getY())->setUnit(&unit0);

    cout << "Game running !" << endl;

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

        getAllowedMoves(&unit0, &moves);

        gameDisplay.clearVectorHighlight();
        gameDisplay.updateVectorHighlight(moves, BLUE);

        gameDisplay.updateDisplay();

        t = clock() - t;

        usleep((unsigned int)((1.0/FRAMERATE-(double)t/CLOCKS_PER_SEC)*1000000));
    }
}

int Game::verifMoves(Rect src, int count, int posTabX, int posTabY, int* nmbMovePoints, int remainingMoves, Unit* unit, vector<vector<int>>* moves)
{
  if((count <= *nmbMovePoints) && (remainingMoves > 0))
  {
    if(((*moves)[posTabX - 1][posTabY] < count) &&
      (unit->getMoveMalus(gameMap.getTile(src.getX() - 1, src.getY())->getNameTerrain()) >= 0))
      {
          (*moves)[posTabX - 1][posTabY] = count;
          Rect new_src = Rect(src.getX() - 1, src.getY(), src.getW(), src.getH());
          remainingMoves -= unit->getMoveMalus(gameMap.getTile(src.getX() - 1, src.getY())->getNameTerrain());
          verifMoves(new_src, count + 1, posTabX - 1, posTabY, nmbMovePoints, remainingMoves, unit, moves);
      }
    if(((*moves)[posTabX][posTabY - 1] < count) &&
      (unit->getMoveMalus(gameMap.getTile(src.getX(), src.getY() - 1)->getNameTerrain()) >= 0))
      {
          (*moves)[posTabX][posTabY - 1] = count;
          Rect new_src = Rect(src.getX(), src.getY() - 1, src.getW(), src.getH());
          remainingMoves -= unit->getMoveMalus(gameMap.getTile(src.getX(), src.getY() - 1)->getNameTerrain());
          verifMoves(new_src, count + 1, posTabX, posTabY - 1, nmbMovePoints, remainingMoves, unit, moves);
      }
    if(((*moves)[posTabX + 1][posTabY] < count) &&
      (unit->getMoveMalus(gameMap.getTile(src.getX() + 1, src.getY())->getNameTerrain()) >= 0))
      {
          (*moves)[posTabX + 1][posTabY] = count;
          Rect new_src = Rect(src.getX() + 1, src.getY(), src.getW(), src.getH());
          remainingMoves -= unit->getMoveMalus(gameMap.getTile(src.getX() + 1, src.getY())->getNameTerrain());
          verifMoves(new_src, count + 1, posTabX + 1, posTabY, nmbMovePoints, remainingMoves, unit, moves);
      }
    if(((*moves)[posTabX][posTabY + 1] < count) &&
      (unit->getMoveMalus(gameMap.getTile(src.getX(), src.getY() + 1)->getNameTerrain()) >= 0))
      {
          (*moves)[posTabX][posTabY + 1] = count;
          Rect new_src = Rect(src.getX(), src.getY() + 1, src.getW(), src.getH());
          remainingMoves -= unit->getMoveMalus(gameMap.getTile(src.getX(), src.getY() + 1)->getNameTerrain());
          verifMoves(new_src, count + 1, posTabX, posTabY + 1, nmbMovePoints, remainingMoves, unit, moves);
      }
  } else { return 1;}
}
