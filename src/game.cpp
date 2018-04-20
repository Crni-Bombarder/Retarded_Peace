#include "game.h"

Game::Game()
{

}

Game::Game(string _mapFile)
{
    gameMap = Map(_mapFile);
    mapFile = _mapFile;
    libImages = VectorImage();
    gameDisplay = Display(&mapFile, &libImages);
    gameRunning = false;
}

Game::~Game()
{

}

void Game::setMapFile(string _mapFile)
{
    mapFile = _mapFile;
}

bool Game::StartGame(void)
{
    gameRunning = true;
    gameThread = new thread(loop);
}

bool Game::StopGame(void)
{
    gameRunning = false;
    gameThread->join();
    delete gameThread;
}

void Game::loop()
{

}
