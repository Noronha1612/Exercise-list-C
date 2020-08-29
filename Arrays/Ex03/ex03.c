#include "stdio.h"

/*

Escreva um programa que leia 10 números inteiros e os armazene em um vetor. 
Imprima o vetor, o maior elemento e a posição que ele se encontra.


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

    int biggest = 0, biggestPosition;

    for ( int x = 0; x < 10; x++ ) {
        if ( numArray[x] > biggest || biggest == 0 ) {
            biggest = numArray[x];
            biggestPosition = x;
        }
    }

    printf("\nThe biggest number you tipped was: %i\n", biggest);
    printf("Which position on array is %i\n", biggestPosition);

    return 0;
}