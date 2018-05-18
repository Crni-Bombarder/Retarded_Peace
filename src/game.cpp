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
    libImages.loadImage("data/textures/highlight.png");

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
  int coord_X, coord_Y;
  int nmbMovePoints = TypeUnit::getTypeUnit(unit->getStrType())->getMovePoints();
  allowedMoves->resize(0);
  int tabSize = (nmbMovePoints*2 + 1);
  vector<vector<int>> moves = vector<vector<int>>(tabSize, vector<int>(tabSize));
  for(i = 0; i < tabSize; i++)
  {
    for(j = 0; j < tabSize; j++)
    {
          moves[i][j] = -1;
    }
  }

  moves[tabSize/2][tabSize/2] = nmbMovePoints;
  verifMoves(unit->getPosition(), tabSize/2, tabSize/2, nmbMovePoints, unit, &moves);

  for (i = 0; i < tabSize; i++)
  {
    for(j = 0; j < tabSize; j++)
    {
        coord_X = unit->getPosition().getX() - (tabSize/2 - i);
        coord_Y = unit->getPosition().getY() - (tabSize/2 - j);
        if((coord_X >= 0) && (coord_X < gameMap.getNmbTilesX()) && (coord_Y >= 0) && (coord_Y < gameMap.getNmbTilesY()))
        {
            if((moves[i][j] >= 0) && (moves[i][j] < nmbMovePoints) && (gameMap.getUnitFromTiles(coord_X, coord_Y) == nullptr))
            {
                Rect addRect = Rect(coord_X, coord_Y);
                allowedMoves->push_back(addRect);
            }
        }
    }
}
}

void Game::printAllowedMoves(vector<Rect>* allowedMoves)
{
  for(int i = 0; i < allowedMoves->size(); i++)
  {
    cout << "Move " << i << " -> X : " << (*allowedMoves)[i].getX() << " Y : " << (*allowedMoves)[i].getY() << endl;
  }
}

void Game::loop()
{
    cout << "Create dummy unit" << endl;
    vector<Rect> moves = vector<Rect>();

    SDL_Event event;
    clock_t t;

    Unit unit0("infanterie", 0);
    Unit unit1("infanterie", 1);
    Rect position1(5, 3);
    Rect position0(5, 5);
    unit0.setPosition(position0);
    unit1.setPosition(position1);
    gameMap.getTile(position0.getX(), position0.getY())->setUnit(&unit0);
    gameMap.getTile(position1.getX(), position1.getY())->setUnit(&unit1);
    getAllowedMoves(&unit0, &moves);

    gameDisplay.clearVectorHighlight();
    gameDisplay.updateVectorHighlight(moves, BLUE);
    printAllowedMoves(&moves);
    gameDisplay.updateDisplay();

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


        gameDisplay.updateDisplay();

        t = clock() - t;

        usleep((unsigned int)((1.0/FRAMERATE-(double)t/CLOCKS_PER_SEC)*1000000));
    }
}

int Game::verifMoves(Rect src, int posTabX, int posTabY, int remainingMoves, Unit* unit, vector<vector<int>>* moves)
{
  if(remainingMoves > 0)
  {
      int malusLeft, malusUp, malusRight, malusDown;
      bool testLeft, testUp, testRight, testDown;

    if (src.getX() - 1 >= 0
        && (gameMap.getUnitFromTiles(src.getX() - 1, src.getY()) == nullptr || gameMap.getUnitFromTiles(src.getX() - 1, src.getY())->getOwner() == unit->getOwner()))
    {
        malusLeft = unit->getMoveMalus(gameMap.getTile(src.getX() - 1, src.getY())->getNameTerrain());
        testLeft = ((*moves)[posTabX - 1][posTabY] < remainingMoves) && (malusLeft >= 0) && (remainingMoves - malusLeft >= 0);
    } else {
        testLeft = false;
    }
    if (src.getY() - 1 >= 0
        && (gameMap.getUnitFromTiles(src.getX(), src.getY() - 1) == nullptr || gameMap.getUnitFromTiles(src.getX(), src.getY() - 1)->getOwner() == unit->getOwner()))
    {
        malusUp = unit->getMoveMalus(gameMap.getTile(src.getX(), src.getY() - 1)->getNameTerrain());
        testUp = ((*moves)[posTabX][posTabY - 1] < remainingMoves) && (malusUp >= 0) && (remainingMoves - malusUp >= 0);
    } else {
        testUp = false;
    }
    if (src.getX() + 1 < gameMap.getNmbTilesX()
        && (gameMap.getUnitFromTiles(src.getX() + 1, src.getY()) == nullptr || gameMap.getUnitFromTiles(src.getX() + 1, src.getY())->getOwner() == unit->getOwner()))
    {
        malusRight = unit->getMoveMalus(gameMap.getTile(src.getX() + 1, src.getY())->getNameTerrain());
        testRight = ((*moves)[posTabX + 1][posTabY] < remainingMoves) && (malusRight >= 0) && (remainingMoves - malusRight >= 0);
    } else {
        testRight = false;
    }
    if (src.getY() + 1 < gameMap.getNmbTilesY()
        && (gameMap.getUnitFromTiles(src.getX(), src.getY() + 1) == nullptr || gameMap.getUnitFromTiles(src.getX(), src.getY() + 1)->getOwner() == unit->getOwner()))
    {
        malusDown = unit->getMoveMalus(gameMap.getTile(src.getX(), src.getY() + 1)->getNameTerrain());
        testDown = ((*moves)[posTabX][posTabY + 1] < remainingMoves) && (malusDown >= 0) && (remainingMoves - malusDown >= 0);
    } else {
        testDown = false;
    }

    if(testLeft)
      {
          (*moves)[posTabX - 1][posTabY] = remainingMoves - malusLeft;

          // Rect new_src = Rect(src.getX() - 1, src.getY(), src.getW(), src.getH());
          // remainingMoves -= unit->getMoveMalus(gameMap.getTile(src.getX() - 1, src.getY())->getNameTerrain());
          // verifMoves(new_src, count + 1, posTabX - 1, posTabY, nmbMovePoints, remainingMoves, unit, moves);
      }
    if(testUp)
      {
          (*moves)[posTabX][posTabY - 1] = remainingMoves - malusUp;
          // Rect new_src = Rect(src.getX(), src.getY() - 1, src.getW(), src.getH());
          // remainingMoves -= unit->getMoveMalus(gameMap.getTile(src.getX(), src.getY() - 1)->getNameTerrain());
          // verifMoves(new_src, count + 1, posTabX, posTabY - 1, nmbMovePoints, remainingMoves, unit, moves);
      }
    if(testRight)
      {
          (*moves)[posTabX + 1][posTabY] = remainingMoves - malusRight;
          // Rect new_src = Rect(src.getX() + 1, src.getY(), src.getW(), src.getH());
          // remainingMoves -= unit->getMoveMalus(gameMap.getTile(src.getX() + 1, src.getY())->getNameTerrain());
          // verifMoves(new_src, count + 1, posTabX + 1, posTabY, nmbMovePoints, remainingMoves, unit, moves);
      }
    if(testDown)
      {
          (*moves)[posTabX][posTabY + 1] = remainingMoves - malusDown;
          // Rect new_src = Rect(src.getX(), src.getY() + 1, src.getW(), src.getH());
          // remainingMoves -= unit->getMoveMalus(gameMap.getTile(src.getX(), src.getY() + 1)->getNameTerrain());
          // verifMoves(new_src, count + 1, posTabX, posTabY + 1, nmbMovePoints, remainingMoves, unit, moves);
      }
    if(testLeft)
    {
      verifMoves(Rect(src.getX() - 1, src.getY()), posTabX - 1, posTabY, remainingMoves - malusLeft, unit, moves);
    }
    if(testUp)
    {
      verifMoves(Rect(src.getX(), src.getY() - 1), posTabX, posTabY - 1, remainingMoves - malusUp, unit, moves);
    }
    if(testRight)
    {
      verifMoves(Rect(src.getX() + 1, src.getY()), posTabX + 1, posTabY, remainingMoves - malusRight, unit, moves);
    }
    if(testDown)
    {
      verifMoves(Rect(src.getX(), src.getY() + 1), posTabX, posTabY + 1, remainingMoves - malusDown, unit, moves);
    }
  } else { return 1;}
  return 0;
}
