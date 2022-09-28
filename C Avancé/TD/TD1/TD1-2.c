#include <stdio.h>

void draw2(int nbL, int nbC) {
    int i,j,blue = nbC, black=0;

    printf("P3\n%d %d\n255\n", nbC, nbL);

    for ( i = 0; i < nbL; i++) {
        for(j=blue; j>0 ; j--){
            printf("0 0 255\n");
        }
        for(j=0;j<black;j++){
            printf("0 0 0\n");
        }
        blue--;
        black++;
    }
}


int main() {
    draw2(500, 500);
    return 0;
}