#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void createList(int* tab, int size){
    int i;
    srand(time(NULL));
    for(i=0; i<size ;i++){
        tab[i] = rand() % 1000;
    }
}

void displayList(int tab[],int size){
    printf("\n");
    for(int i = 0; i<size;i++){
        printf("%d ", tab[i]);
    }
    printf("\n");
}

unsigned int isSorted(int tab[], int size){
    int before = 0;
    int actual = 1;
    while(actual != size){
        if(tab[actual]<tab[before]){
            return 0;
        }
        before++;
        actual++;
    }
    return 1;
}

void selectionSort(int* tab,int size){
    int i,j,c;
    for(i=0;i<size-1;i++){
        for(j=i+1;j<size;j++){
            if ( tab[i] > tab[j] ) {
                c = tab[i];
                tab[i] = tab[j];
                tab[j] = c;
            }
        }
    }
}

void insertionSort(int* tab,int size){
    int i,j,k,c;
    for(i=1;i<size;i++) {
        if ( tab[i] < tab[i-1] ) { 
            j = 0;
            while ( tab[j] < tab[i] ) j++; 
            c = tab[i]; 
            for( k = i-1 ; k >= j ; k-- ) tab[k+1] = tab[k];
            tab[j] = c; 
        }
    }   
}

int main(void){
    int tab[SIZE];
    createList(tab,SIZE);
    displayList(tab,SIZE);
    insertionSort(tab,SIZE);
    displayList(tab,SIZE);
    printf("%s", isSorted(tab,SIZE) == 1? "The array is sorted" : "The array is not sorted");
    return 0;
}