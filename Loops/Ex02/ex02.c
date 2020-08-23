#include "stdio.h"

int main() {

    int mainNumber, sum = 0;

    while(1) {
        printf("Type a positive integer:");
        scanf("%i", &mainNumber);

        if ( mainNumber > 0 ) break;
        printf("Please, type a valid positive integer.\n");
    }

    printf("The sum of all the divisors of %i is: ", mainNumber);

    for ( int possibleDivider = 1; possibleDivider < mainNumber; possibleDivider++ ) {
        if ( mainNumber % possibleDivider == 0 ) {
            printf(possibleDivider == 1 ? "%i" : " + %i", possibleDivider );

            sum = sum + possibleDivider;
        }
    }

    printf(" = %i\n", sum);

    return 0;
}