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

    static TypeUnit* getTypeUnit(string _typeName);
protected:
    string name;
    int idImage;
    std::map<string, int> moveMalus;

    static std::map<string, TypeUnit*> mapTypeUnit;
};

#endif
