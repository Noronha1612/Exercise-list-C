#include "stdio.h"

int main() {
    int number;

    printf("Type an integer: ");
    scanf("%i", &number);
    getchar();

    for ( int multiplier = 1; multiplier <= 10; multiplier++ ) {
        printf("\n%i x %i = %i\n", number, multiplier, number * multiplier);
    }

    return 0;
}