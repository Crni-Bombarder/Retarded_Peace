#include "headers/vector_image.h"

using namespace std;

vector<Image> vectorImage = vector<Image>();

VectorImage() {}
~VectorImage() {}

void initVector(void)
{
    vectorImage.resize(0);
}

bool loadImage(string _imageName)
{
    Image image = Image(_imageName);
    vectorImage.push_back(image);
}

int loadDirectory(string _directory)
{
    string path = "textures" + _directory;
    for(string* p : filesystem::directory_iterator(path))
    {
        cout << p << endl;
    }
}

int getSize(void)
{
    return vectorImage.size();
}

Image* getImageFromIndex(int _index)
{
    return &vectorImage[_index];
}
