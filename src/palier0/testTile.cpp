#include "../headers/tile.h"

int main(int argc, char* argv[])
{
    Tile firstTile;
    Tile secondTile(3);
    Tile thirdTile(1);
    Tile fourthTile;

    firstTile.printTile();
    secondTile.printVectorTile();
    return 0;
}

