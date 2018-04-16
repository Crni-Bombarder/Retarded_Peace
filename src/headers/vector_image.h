#ifndef VECTOR_IMAGE_H
#define VECTOR_IMAGE_H

#include <string>
#include <vector>
#include <iostream>
#include <filesystem>

#include "image.h"

class VectorImage{

public:

  VectorImage();
  ~VectorImage();

  void initVector(void);
  bool loadImage(String _imageName);
  int loadDirectory(String _directory);
  int getSize(void);
  Image* getImageFromIndex(int _index);

private:

  vector<Image> vectorImage;

};

#endif
