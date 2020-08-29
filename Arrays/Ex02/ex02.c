#include "stdio.h"
#include "stdlib.h"
#include "time.h"

/*

Faça um programa que pede que o usuário digite um número inteiro positivo maior que zero 
e armazene na variável TAM. Enquanto o usuário digitar um número inválido, peça para que ele redigite. 
Um vez definido o valor de TAM, crie um vetor com TAM elementos. 
Inicialize o vetor com valores aleatórios entre 0-100. Uma vez preenchido, 
armazene em um segundo vetor cada valor do primeiro vetor só que elevado ao quadrado. 
Imprima o segundo vetor.

*/

int main() {

    int TAM;

    while(1) {
        printf("Type the length: ");
        scanf("%i", &TAM);
        getchar();

        if ( TAM > 0 ) break;
        printf("Type a valid length.\n");
    }

    double initialArray[TAM], poweredArray[TAM];

    srand(time(NULL));

    for ( int x = 0; x < TAM; x++ ) {
        int randomNumber = rand() % 100;

        initialArray[x] = (double) randomNumber;
    }

    for ( int x = 0; x < TAM; x++ ) {
        poweredArray[x] = initialArray[x] * initialArray[x];
    }

    printf("Powered array elements: ");
    for ( int x = 0; x < TAM; x++ ) {
        printf("%.0lf ", poweredArray[x]);
    }

    printf("\n");

    return 0;
}