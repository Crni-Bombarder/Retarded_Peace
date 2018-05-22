#ifndef TYPEUNIT_H
#define TYPEUNIT_H

#include <map>
#include <string>

using namespace std;

class TypeUnit{
public:
    TypeUnit();
    ~TypeUnit();

    TypeUnit(string _typeName);

    int getIdImage();
    int getMoveMalus(string _terrainName);
    int getMinRange();
    int getMaxRange();
    int getAttackValue(string _target);
    int getMovePoints();

    bool canMoveAttack();
    bool canAttack();

    static TypeUnit* getTypeUnit(string _typeName);
protected:
    string name;
    int idImage;

    int movePoints;
    std::map<string, int> moveMalus;

    int minRange;
    int maxRange;
    bool moveAttack;
    bool attack;
    std::map<string, int> attackValue;

    static std::map<string, TypeUnit*> mapTypeUnit;
};

#endif
