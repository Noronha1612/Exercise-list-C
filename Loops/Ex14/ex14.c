#include "stdio.h"

/*

Dados um número inteiro N, N>0, e uma sequência com N números inteiros maiores do que zero, 
determinar o fatorial de cada número da sequência.

*/

int main() {

    int num;

    while(1) {
        printf("Type a positive integer: ");
        scanf("%i", &num);
        getchar();

        if ( num > 0 ) break;
        printf("Please, follow the instructions...\n");
    }

    int fact = 1;

    printf("\n%i! = ", num);

    for ( int multiplier = num; multiplier >= 1; multiplier-- ) {
        fact *= multiplier;

        if ( multiplier == num ) printf("%i", multiplier);
        else printf(" x %i", multiplier);
    }

    printf(" = %i\n", fact);
    

    return 0;
}