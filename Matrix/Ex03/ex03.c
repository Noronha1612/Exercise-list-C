#include "stdio.h"
#include "stdlib.h"
#include "time.h"

/*

Preencha duas matrizes 4 x 4 de forma aleatória com valores entre 0 e 20, 
e escreva uma terceira com os maiores valores de cada posição das matrizes preenchidas.

*/

void fillMatrix(int matrix[4][4]) {

    for ( int x = 0; x < 4; x++ ) {
        for ( int y = 0; y < 4; y++ ) {
            matrix[x][y] = rand() % 21; 
        }
    }
}

int main() {

    int matrix1[4][4], matrix2[4][4], matrix3[4][4];
    
    srand(time(NULL));

    fillMatrix(matrix1);
    fillMatrix(matrix2);

    for ( int x = 0; x < 4; x++ ) {
        for ( int y = 0; y < 4; y++ ) {
            matrix3[x][y] = matrix1[x][y] > matrix2[x][y] ? matrix1[x][y] : matrix2[x][y];
        }
    }

    printf("\nBigger Matrix:\n");

    for ( int x = 0; x < 4; x++ ) {
        for ( int y = 0; y < 4; y++ ) {
            printf("%i ", matrix3[x][y]);
        }

        printf("\n");
    }

    return 0;
}