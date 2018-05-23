#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

#include "unit.h"
#include "rect.h"

class Player {
public:
    Player();
    ~Player();

    int getId();
    static int getNmbPlayer();

    Unit* creatUnit(Rect _pos, string _type);
    int getNumberUnit();
    void deleteUnit(Unit* _unit);
    void refreshUnit();

    Rect getCursorPosition();
    Rect getScreenPosition();
    void setCursorPosition(Rect _position);
    void setScreenPosition(Rect _position);

    static Player* getPlayerFromId(int _id);

private:
    int id;
    vector<Unit*> units;

    Rect posCursor;
    Rect posScreen;
    static int nmbPlayer;
    static vector<Player*> vectPlayer;
};

#endif
