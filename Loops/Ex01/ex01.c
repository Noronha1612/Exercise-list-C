#include "stdio.h"
#include "math.h"

int main() {

    int total = 0, validNumbers = 0;

    printf("Please, type 10 integers:\n\n");

    for ( int x = 1; x <= 10; x++ ) {
        int number;

        printf("Number %i:", x);
        scanf("%i", &number);

        if ( number >= 0 ) {
            total = total + number;
            validNumbers++;
        }
    }

    double average = (double) total / (double) validNumbers;

    printf("\nAverage(Ignoring the negative ones): ");

    if ( fmod(average, 1) == 0 ) printf("%i\n", (int) average);
    else printf("%.2lf\n", average);

    return 0;
}