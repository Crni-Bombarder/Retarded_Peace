#ifndef VECTOR_IMAGE_H
#define VECTOR_IMAGE_H

#include <string>
#include <vector>

#include "image.h"

class VectorImage{

public:

  VectorImage();
  ~VectorImage();

  void initVector(void);
  int loadDirectory(String directory);
  int getSize(void);
  Image* getImageFromIndex(int _index);

private:

  vector<Image> vectorImage;

};

#endif
