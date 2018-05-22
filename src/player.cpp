#include "player.h"

vector<Player*> Player::vectPlayer = vector<Player*>();
int Player::nmbPlayer = 0;

Player::Player()
{
    id = nmbPlayer;
    nmbPlayer++;
    units = vector<Unit*>();
    vectPlayer.push_back(this);
}

Player::~Player()
{
    for (int i = 0; i<units.size(); i++)
    {
        delete units[i];
    }
}

int Player::getId()
{
    return id;
}

int Player::getNmbPlayer()
{
    return nmbPlayer;
}

Unit* Player::creatUnit(Rect _pos, string _type)
{
    Unit* newUnit = new Unit(_pos, _type, id);
    units.push_back(newUnit);
    return newUnit;
}

void Player::deleteUnit(Unit* _unit)
{
    int i = 0;
    Unit* value = units[0];
    while(value != _unit)
    {
        i++;
        value = units[i];
    }
    delete _unit;
    units.erase(units.begin() + i);
}

void Player::refreshUnit()
{
    for(int i = 0; i <units.size(); i++)
    {
        units[i]->setMoved(false);
    }
}

Player* Player::getPlayerFromId(int _id)
{
    return vectPlayer[_id];
}
