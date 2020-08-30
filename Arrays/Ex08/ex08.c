#include "stdio.h"

/*

Faça um programa que cria um vetor de 10 elementos inteiros. 
Inicialize cada posição do vetor com o valor -1. Posições com o valor -1, significam que estão disponíveis.
O programa deve pedir para que o usuário digite dois valores: 
o valor a ser adicionado no vetor e o índice (entre 0-9) em que o valor digitado será inserido no vetor. 
Se o índice digitado diz respeito à uma posição disponível do vetor (valor igual a -1), o valor é inserido. 
Caso contrário, deve-se imprimir uma mensagem informando que aquela posição já foi preenchida. 
O programa deve ser encerrado quando todas as posições estiverem preenchidas

*/

int main() {
    
    int mainArray[10];

    for ( int x = 0; x < 10; x++ ) {
        mainArray[x] = -1;
    }

    while(1) {
        int value;

        while(1) {
            printf("Type an integer(cannot be -1): ");
            scanf("%i", &value);
            getchar();

            if ( value != -1 ) break;
            printf("Please, do not type -1.\n");
        }

        printf("\nAvailable positions:");
        for ( int x = 0; x < 10; x++ ) {
            if ( mainArray[x] == -1 ) printf(" %i", x);
        }
        printf("\n");

        int index;

        while(1) {
            printf("Choose a position: ");
            scanf("%i", &index);
            getchar();

            if ( mainArray[index] == -1 ) break;
            printf("Please, select an available position.\n");
        }
        printf("\n");

        mainArray[index] = value;

        int hasAllBeenReplaced = 1;

        for ( int x = 0; x < 10; x++ ) {
            if ( mainArray[x] == -1 ) hasAllBeenReplaced = 0;
        }

        if ( hasAllBeenReplaced ) break;
    }

    printf("\nEvery positions has been setted!\n");

    return 0;
}