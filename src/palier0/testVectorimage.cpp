#include "vector_image.h"


int main(void)
{
    VectorImage vi = VectorImage();
    vi.initVector();
    vi.loadImage("bin/textures/test0.png");
    (vi.getImageFromIndex(0))->print();

    return 0;
}
