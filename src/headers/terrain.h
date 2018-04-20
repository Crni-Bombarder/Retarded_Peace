#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>

class Terrain {
public:
    Terrain();
    Terrain(int _idImage);
    ~Terrain();

    int getIdImage(void);
    void setIdImage(int _idImage);

    static Terrain* getTerrainFromId(int _id);
private:
    int idImage;

    static vector<Terrain*> vectorTerrain;

    static void addTerrainToVector(Terrain * _pterrain);
};

#endif
