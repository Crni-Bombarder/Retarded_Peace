#include "../headers/color.h"

int main(void)
{
  Color vide;
  Color red(255, 0, 0);
  Color blue(0, 255, 0);
  Color alpha(0, 0, 54, 122);

  vide.print();
  red.print();
  blue.print();
  alpha.print();
  return 0;
}
