#include "vector_image.h"

int main(void)
{
    VectorImage vi = VectorImage();
    vi.initVector();
    vi.loadDirectory("textures");
    return 0;
}
