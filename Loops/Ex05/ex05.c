#include "stdio.h"

int main() {

    int number;

    while(1) {
        printf("Type a positive integer: ");
        scanf("%i", &number);
        getchar();

        if ( number > 0 ) break;
        printf("Please, a positive integer number.\n");
    }

    int isNumberOdd = 1;

    for (int someNumberBetween = number - 1; someNumberBetween > 1; someNumberBetween--) {
        if ( number % someNumberBetween == 0 ) isNumberOdd = 0;
    }

    if ( isNumberOdd ) printf("Yepp, the number %i is odd!", number);
    else printf("Nopp, the number %i is not odd.", number);

    return 0;
}