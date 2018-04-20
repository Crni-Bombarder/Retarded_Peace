#include "headers/vector_image.h"

using namespace std;

VectorImage::VectorImage() {
    vector<Image> vectorImage = vector<Image>();
}
VectorImage::~VectorImage() {}

void VectorImage::initVector(void)
{
    vectorImage.resize(0);
}

bool VectorImage::loadImage(string _imageName)
{
    Image image = Image(_imageName);
    vectorImage.push_back(image);
}

int VectorImage::getSize(void)
{
    return vectorImage.size();
}

Image* VectorImage::getImageFromIndex(int _index)
{
    return &vectorImage[_index];
}
