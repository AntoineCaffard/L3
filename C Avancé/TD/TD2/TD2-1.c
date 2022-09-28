#include <stdio.h>


void drawJacquard(int nbL, int nbC, int nbSplitX, int nbSplitY) {
  int i, j, r;
  int couleur;
  int stepX = nbC / nbSplitX;
  int stepY = nbL / nbSplitY;

  printf("P3\n%d %d\n255\n", nbC, nbL);

  for (i = 0; i < nbL; i++)
    for (j = 0; j < nbC; j++) {
      int li = ((double)stepX / stepY) * (i % stepY);
      int lj = j % stepX;

      r = (i / stepY) % 2;
      couleur = 255 * r;
      if ((r + (j / stepX)) % 2 == 0) {
        if (li < stepX - lj) couleur = 255 - couleur;
      } else {
        if (li < lj) couleur = 255 - couleur;
      }

      printf("100 %d %d\n", couleur, couleur);
    }
}

int main() {
  drawJacquard(500, 500, 20, 10);
  return 0;
}