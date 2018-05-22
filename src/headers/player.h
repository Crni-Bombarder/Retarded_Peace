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
    void deleteUnit(Unit* _unit);
    void refreshUnit();

    static Player* getPlayerFromId(int _id);

private:
    int id;
    vector<Unit*> units;
    static int nmbPlayer;
    static vector<Player*> vectPlayer;
};

#endif
