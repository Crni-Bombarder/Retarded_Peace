#include "vector_image.h"

int main(void)
{
    VectorImage vi = VectorImage();
    vi.initVector();
    vi.loadImage("textures/test0.png");
    return 0;
}
