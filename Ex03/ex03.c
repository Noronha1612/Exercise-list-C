#include "stdio.h"

int main() {

    int A, B;

    printf("Type the value of A:");
    scanf("%i", &A);
    
    printf("Type the value of B:");
    scanf("%i", &B);

    if ( A % B == 0 ) {
        printf("\nThe number %i is divisible by %i\n", A, B);
    }
    else {
        printf("\nThe number %i is not divisible by %i\n", A, B);
    }

    return 0;
}