#include "../headers/tile.h"

int main(int argc, char* argv[])
{
    Tile firstTile;
    Tile secondTile("mer");
    Tile thirdTile("plaine");
    Tile fourthTile;

    firstTile.printTile();
    secondTile.printTile();
    return 0;
}
