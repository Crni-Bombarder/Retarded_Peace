#include "vector_image.h"

#include <cv.hpp>

int main(void)
{
    VectorImage vi = VectorImage();
    vi.initVector();
    vi.loadImage("bin/textures/test0.png");
    (vi.getImageFromIndex(0))->print();

    namedWindow("Tamere", WINDOW_AUTOSIZE);
    imshow("Tamere", *(vi.getImageFromIndex(0)->getMat()));

    waitKey(0);

    return 0;
}
