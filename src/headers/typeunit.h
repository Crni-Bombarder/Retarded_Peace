#ifndef TYPEUNIT_H
#define TYPEUNIT_H

#include <map>
#include <string>

class TypeUnit{
public:
    TypeUnit();
    ~TypeUnit();

    TypeUnit(String _typeName);

    int getIdImage();
    int getMoveMalus(String _terrainName);

    static TypeUnit* getTypeUnit(String _typeName);
private:
    String name;
    int idImage;
    std::map<String, int> moveMalus;

    static std::map<String, TypeUnit*> mapTypeUnit;
};

#endif
