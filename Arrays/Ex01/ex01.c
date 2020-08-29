#include "stdio.h"
#include "math.h"

/*

Faça um programa que preencha um vetor com 10 números reais, 
calcule e mostre a quantidade de números negativos e a soma dos números positivos desse vetor.

*/

int main() {

    int arrayLength = 10;

    float array[arrayLength];

    for ( int e = 0; e < arrayLength; e++ ) {
        float element;

        printf("Type the %i element: ", e + 1);
        scanf("%f", &element);

        array[e] = element;
    }

    int negativeQuantity = 0;
    float sumPositive = 0;

    for ( int x = 0; x < arrayLength; x++ ) {
        if ( array[x] < 0 ) negativeQuantity++;
        if ( array[x] > 0 ) sumPositive += array[x];
    }

    printf("\nResult\n");

    printf("Quantity of negative numbers: %i\n", negativeQuantity);
    printf("Sum of the positive numbers: ");
    fmodf(sumPositive, 1) == 0 ?
    printf("%i", (int) sumPositive) :
    printf("%.2f", sumPositive);

    return 0;
}