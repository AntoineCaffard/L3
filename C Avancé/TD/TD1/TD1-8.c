#include <stdio.h>

// Fonction permettant de permuter deux variables

int main() {
    int num1, num2;
    scanf("%d%d", &num1, &num2);
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);
    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;
    printf("num1 aprés le swap = %d\n", num1);
    printf("num2 aprés le swap = %d\n", num2);
    return 0;
}
