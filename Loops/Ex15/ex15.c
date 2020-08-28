#include "stdio.h"

int main() {

    int size;

    while(1) {
        printf("Type the size of the square: ");
        scanf("%i", &size);
        getchar();

        if ( size > 0 ) break;
        printf("Please, type a valid size.");
    }

    for ( int line = 0; line < size; line++ ) {
        for ( int column = 1; column <= size; column++ ) {
            if ( column == line + 1 || column == size - line ) printf("x");
            else printf(" ");
        }
        printf("\n");
    }

    return 0;
}