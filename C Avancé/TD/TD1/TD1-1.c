#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void drawRandom(int nbL, int nbC) {
     int i, j, r, g, b;
    int couleur;

    srand(time(NULL));
    printf("P3\n%d %d\n255\n", nbC, nbL);

    for (i = 0; i < nbL; i++) {
        for (j = 0; j < nbC; j++) {
            r = rand() % 256;
            g = rand() % 256;
            b = rand() % 256;
            printf("%d %d %d\n", r,g,b);
        }
    }
}


int main() {
    drawRandom(500, 500);
    return 0;
}