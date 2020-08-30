#include "stdio.h"

/*

Faça um programa que leia dois vetores de 10 posições e calcule outro vetor contendo, 
nas posições pares os valores do primeiro e nas posições ímpares os valores do segundo.

*/

void readArrayElements(int arr[]) {
    for ( int x = 0; x < 10; x++ ) {
        int element;

        printf("Type the %i element: ", x + 1);
        scanf("%i", &element);
        getchar();

        arr[x] = element;
    }
}

int main() {

    int array1[10], array2[10], array3[20];

    printf("Elements of first array:\n");
    readArrayElements(array1);

    printf("\nElements of second array:\n");
    readArrayElements(array2);

    int counterArray1 = 0, counterArray2 = 0;

    for ( int x = 0; x < 20; x++ ) {
        if ( x % 2 == 0 ) {
            array3[x] = array1[counterArray1];
            counterArray1++;
        } else {
            array3[x] = array2[counterArray2];
            counterArray2++;
        }
    }

    printf("\nElements of third array (Array1 U Array2):\n");
    for ( int x = 0; x < 20; x++ ) {
        printf("%i ", array3[x]);
    } 

    printf("\n");

    return 0;
}