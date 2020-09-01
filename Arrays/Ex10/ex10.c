#include "stdio.h"
#include "stdlib.h"
#include "time.h"

/*

Inicialize um vetor com 20 números inteiros aleatórios entre 0 e 10. 
Escreva os elementos do vetor eliminando os elementos repetidos.

*/

int main() {

    int array[20];
    
    srand(time(NULL));

    for ( int x = 0; x < 20; x++ ) {
        array[x] = rand() % 10;
    }

    int cleanArray[20];
    int counterCleanArray = 0;
    int has0 = 0;

    for ( int x = 0; x < 20; x++ ) {
        int element = array[x];
        int hasElementAlreadyExist = 0;

        for ( int y = 0; y < 20; y++ ) {
            if ( cleanArray[y] == element ) {
                hasElementAlreadyExist = 1;

                if ( element == 0 && !has0 ) {
                    hasElementAlreadyExist = 0;
                    has0 = 1;
                }
            }
        }

        if ( !hasElementAlreadyExist ) {
            cleanArray[counterCleanArray++] = element;
        }
    }

    printf("Elements complete: ");

    for ( int x = 0; x < 20; x++ ) {
        printf(" %i", array[x]);
    }

    printf("\nElements without repetitions: ");

    for ( int x = 0; x < counterCleanArray; x++ ) {
        printf(" %i", cleanArray[x]);
    }

    printf("\n");

    return 0;
}