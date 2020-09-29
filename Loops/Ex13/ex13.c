#include "stdio.h"

/*

Usando apenas os comandos printf("0"), printf("*") e printf("\n") e usando laços aninhados,
faça o seguinte aparecer na tela.
xxxxx
0xxxx
00xxx
000xx
0000x
00000


*/

int main() {

    for ( int line = 0; line <= 5; line++ ) {

        for ( int times0 = 0; times0 < line; times0++ ) {
            printf("0");
        }

        for ( int timesX = 5; timesX > line; timesX-- ) {
            printf("x");
        }
        printf("\n");
    }

    return 0;
}