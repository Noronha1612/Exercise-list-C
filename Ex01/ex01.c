#include "stdio.h"
#include "stdlib.h"

int main() {
    int num1, num2;

    printf("Type the number 1 as an integer:");
    scanf("%i", &num1);

    printf("Type the number 2 as an integer:");
    scanf("%i", &num2);

    int sum = num1 + num2;

    if ( sum >= 10 ) {
        printf("\nThe sum of %i and %i is equal to %i\n", num1, num2, sum);
    }
    else {
        printf("\nThe sum is lower than 10\n");
    }

    return 0;
}