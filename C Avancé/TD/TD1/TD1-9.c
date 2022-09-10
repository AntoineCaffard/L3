#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    while(n!=1 && n%2 == 0){
        n = n/2;
    }
    printf( n == 1 ? "Puissance de 2" : "Pas Puissance de 2");
    return 0;
}
