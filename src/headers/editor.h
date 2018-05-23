#ifndef EDITOR_H
#define EDITOR_H

#include <string>

#include "game.h"

class Editor : public Game {
public:
    Editor();
    Editor(string _mapFile);
    Editor(int _nmbTileX, int _nmbTileY, string _mapFile);

    ~Editor();

private:
    void loop();
};

#endif
