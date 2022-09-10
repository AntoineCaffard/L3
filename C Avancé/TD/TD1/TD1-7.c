#include <stdio.h>

// Jeux des batônnets de Fort Boyard

int main() {
    int j1 = 1, j2 = 0, retire = 0, i, restants = 10;
    while( restants>0 ) {
        if( j1 == 1 ) {
            for( i=0; i<restants; i+=1 ) {
                printf( "| " );
            }
            printf( "\nJoueur 1 a vous de jouer : \n" );
            while( retire < 1 || retire > 3 ) {
                scanf( "%d", &retire );
            }
            restants -= retire;
            retire = 0;
            j1 = 0;
            j2 = 1;
        } else {
            for( i=0; i<restants; i+=1 ) {
                printf( "| " );
            }
            printf( "\nJoueur 2 a vous de jouer : \n" );
            while( retire < 1 || retire > 3 ) {
                scanf( "%d", &retire );
            }
            restants -= retire;
            retire = 0;
            j2 = 0;
            j1 = 1;    
        }
    }
    printf( j1 == 1 ? "Joueur 1 a gagne" : "Joueur 2 a gagne" );
    return 0;
}
