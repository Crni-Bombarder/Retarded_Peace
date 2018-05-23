#include "editor.h"

int main(int argc, char* argv[])
{
    Editor game(40, 40, "mapEditor");
    game.initGame();
    game.StartGame();
}
