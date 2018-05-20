#ifndef TERRAIN_H
#define TERRAIN_H

#include <map>
#include <string>

using namespace std;

class Terrain {
public:
    Terrain();
    Terrain(int _idImage, string _terrainName, int _defenceValue=0);
    ~Terrain();

    string getNameTerrain(void);
    int getIdImage(void);
    int getDefenceValue(void);
    void setIdImage(int _idImage);

    static Terrain* getTerrainFromName(string _name);
private:

    string nameTerrain;
    int idImage;
    int defenceValue;

    static map<string, Terrain*> vectorTerrain;

    static void addTerrainToVector(Terrain * _pterrain);
};

#endif
