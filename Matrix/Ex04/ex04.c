#include "stdio.h"
#include "stdlib.h"
#include "time.h"

/*

Faça um programa para gerar automaticamente números entre 0 e 99 de uma cartela de bingo. 
Sabendo que a cartela deverá conter 5 linhas de 5 números, 
gere estes dados de modo a não ter números repetidos dentro da cartela. 
O programa deve exibir na tela a cartela gerada.

*/

int insertIfNotExist(int matrix[5][5], int element, int indexX, int indexY) {
    int doesElementExist = 0;

    for ( int x = 0; x < 5; x++ ) {
        for ( int y = 0; y < 5; y++ ) {
            if ( matrix[x][y] == element ) doesElementExist = 1;
        }
    }

    if ( !doesElementExist ) {
        matrix[indexX][indexY] = element;
        return 1;
    }

    return 0;
}

void fillMatrix(int matrix[5][5]) {
    for( int x = 0; x < 5; x++ ) {
        for( int y = 0; y < 5; y++ ) {
            while(1) {
                int element = rand() % 100;

                int didInsert = insertIfNotExist(matrix, element, x, y);

                if ( didInsert ) break;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int bingo[5][5];
    fillMatrix(bingo);

    printf("\nBingo:\n");

    for( int x = 0; x < 5; x++ ) {
        for( int y = 0; y < 5; y++ ) {
            printf("%i ", bingo[x][y]);
        }

        printf("\n");
    }

    return 0;
}