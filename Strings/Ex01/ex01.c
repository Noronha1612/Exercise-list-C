#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"

/*

Receber um nome e imprimir as 4 primeiras letras do nome.

*/

int main() {

    char* name = malloc(sizeof(char));

    printf("Type your name: ");
    scanf("%s", name);
    getchar();

    printf("\nThe four first letter of your name are:");

    for ( int x = 0; x < 4; x++ ) {
        printf(" %c", toupper(name[x]));
    }

    printf("\n");

    return 0;
}