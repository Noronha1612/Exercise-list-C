#include "stdio.h"
#include "stdlib.h"
#include "time.h"

/*

Preencha uma matriz 5 x 5 com valores aleatórios entre 0 e 100. 
Em seguida, leia um valor X. O programa deverá fazer uma busca por este valor na matriz e, 
ao final, escrever a localização (linha e coluna), caso a primeira instância desse valor seja encontrado. 
Caso não seja encontrado, imprimir a mensagem “nao encontrado”.

*/

void fillMatrix(int matrix[5][5]) {
    srand(time(NULL));

    for( int x = 0; x < 5; x++ ) {
        for ( int y = 0; y < 5; y++ ) {
            int randomNum = rand() % 100;

            matrix[x][y] = randomNum;
        }
    }
}

int main() {

    int mat[5][5];
    fillMatrix(mat);

    int element;

    while(1) {
        printf("Type an integer between 0 and 100: ");
        scanf("%i", &element);
        getchar();

        if ( element <= 100 && element >= 0 ) break;
        printf("Type a valid number.\n");
    }

    int elementIndex[2];
    elementIndex[0] = -1;
    elementIndex[1] = -1;
    
    for( int x = 0; x < 5; x++ ) {
        for ( int y = 0; y < 5; y++ ) {
            if ( mat[x][y] == element ) {
                elementIndex[0] = x;
                elementIndex[1] = y;
                break;
            }
        }

        if ( elementIndex[0] != -1 ) break;
    }

    if ( elementIndex[0] == -1 ) {
        printf("\nNumber %i has not been found.\n", element);
    }
    else {
        printf("\nNumber %i has been found on line %i and column %i\n", element, elementIndex[0] + 1, elementIndex[1] + 1);
    }

    return 0;
}