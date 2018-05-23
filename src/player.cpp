#include "player.h"

vector<Player*> Player::vectPlayer = vector<Player*>();
int Player::nmbPlayer = 0;

Player::Player()
{
    id = nmbPlayer;
    nmbPlayer++;
    units = vector<Unit*>();
    posCursor = Rect(0,0);
    posScreen = Rect(0,0);
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

int Player::getNumberUnit()
{
    return units.size();
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

Rect Player::getCursorPosition()
{
    return posCursor;
}
Rect Player::getScreenPosition()
{
    return posScreen;
}

void Player::setCursorPosition(Rect _position)
{
    posCursor = _position;
}
void Player::setScreenPosition(Rect _position)
{
    posScreen = _position;
}

Player* Player::getPlayerFromId(int _id)
{
    return vectPlayer[_id];
}
