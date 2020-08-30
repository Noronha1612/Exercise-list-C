#include "stdio.h"

/*

Faça um programa que receba do usuário valores inteiros para dois vetores, A e B, 
com 10 números inteiros cada. Crie um novo vetor denominado C calculando C = A - B. 
Mostre na tela os dados do vetor C.

*/

int main() {

    int A[10], B[10], C[10];

    printf("Elements of A:\n");

    for ( int x = 0; x < 10; x++ ) {
        int element;

        printf("Type the %i element: ", x + 1);
        scanf("%i", &element);
        getchar();

        A[x] = element;
    }

    printf("\nElements of B:\n");

    for ( int x = 0; x < 10; x++ ) {
        int element;

        printf("Type the %i element: ", x + 1);
        scanf("%i", &element);
        getchar();

        B[x] = element;
    }

    for ( int x = 0; x < 10; x++ ) {
        C[x] = A[x] - B[x];
    }

    printf("\nElements of C(A - B):\n");

    for ( int x = 0; x < 10; x++ ) {
        printf("%i (%i - %i)\n", C[x], A[x], B[x]);
    }

    printf("\n");

    return 0;
}