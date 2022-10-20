#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, j, l, r;
  int nbColonne = 256, nbLigne = 256;
  float split = 2 * nbLigne / nbColonne;

  printf("P3\n%d %d\n255\n", nbColonne, nbLigne);

  for (i = 0; i < nbLigne; i++) {
    l = nbColonne / 2 - (i / split);
    r = nbColonne / 2 + (i / split);

    for (j = 0; j < nbColonne; j++) {
      if (l > 0 && r < nbColonne && j >= l && j <= r)
        printf("0 255 255\n");
      else
        printf("0 0 0\n");
    }
  }
  return 0;
}