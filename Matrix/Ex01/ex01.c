#include "stdio.h"

/*

Leia uma matriz 4 x 4, conte e escreva quantos valores maiores que 10 ela possui.

*/

int main() {

    int mat[4][4];

    for( int x = 0; x < 4; x++ ) {
        for ( int y = 0; y < 4; y++ ) {
            int num;

            printf("Type the %ith number on %i line: ", y + 1, x + 1);
            scanf("%i", &num);
            
            mat[x][y] = num;
        }
    }

    int counterBigger10 = 0;
    
    for( int x = 0; x < 4; x++ ) {
        for ( int y = 0; y < 4; y++ ) {
            if ( mat[x][y] >= 10 ) counterBigger10++;
        }
    }

    printf("\nResult:\n");
    printf("Was found %i numbers equal or bigger than 10.\n", counterBigger10);

    return 0;
}