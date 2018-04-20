#ifndef VECTOR_IMAGE_H
#define VECTOR_IMAGE_H

#include <string>
#include <vector>

#include "image.h"

using namespace std;

class VectorImage{

public:

  VectorImage();
  ~VectorImage();

  void initVector(void);
  bool loadImage(string _imageName);
  int getSize(void);
  Image* getImageFromIndex(int _index);

private:

  vector<Image> vectorImage;

};

#endif
