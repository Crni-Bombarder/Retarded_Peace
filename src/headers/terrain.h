#ifndef TERRAIN_H
#define TERRAIN_H

#include <map>
#include <string>

using namespace std;

class Terrain {
public:
    Terrain();
    Terrain(int _idImage, string _terrainName);
    ~Terrain();

    string getNameTerrain(void);
    int getIdImage(void);
    void setIdImage(int _idImage);

    static Terrain* getTerrainFromName(string _name);
private:

    string nameTerrain;
    int idImage;

    static map<string, Terrain*> vectorTerrain;

    static void addTerrainToVector(Terrain * _pterrain);
};

#endif
