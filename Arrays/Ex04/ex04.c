#include "stdio.h"

/*

Leia 10 números inteiros e armazene em um vetor. 
Em seguida imprima os elementos que são primos e suas respectivas posições no vetor.


*/

int main() {

    int numArray[10];

    for ( int x = 0; x < 10; x++ ) {
        int number;

        printf("Type the %i number: ", x + 1);
        scanf("%i", &number);
        getchar();

        numArray[x] = number;
    }

    printf("\nOdd elements and its position:\n");

    for ( int x = 0; x < 10; x++ ) {
        int element = numArray[x] >= 0 ? numArray[x] : -numArray[x] ;
        int isElementOdd = 1;

        for ( int y = element - 1; y > 1; y-- ) {
            if ( element % y == 0 ) isElementOdd = 0;
        }

        if ( isElementOdd && element != 1 && element != 0 ) {
            printf("[ %i, %i ]\n", numArray[x], x);
        }
    }


    return 0;
}