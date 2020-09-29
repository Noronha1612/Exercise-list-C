#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*

Escreva um programa que recebe uma string S e inteiros não-negativos I e J. 
Concatene a frase "Ola mundo" com o segmento S[I..J]. Imprima o texto concatenado.

*/

int readLimitedInteger(char* msg, int min, int max) {
    int value;

    while(1) {
        printf("%s", msg);
        scanf("%i", &value);
        getchar();

        if ( (value <= max || max == -1) && value >= min ) break;
        printf("Type a valid number.\n");
    }

    return value;
}

int main() {

    char S[150];
    int I, J;

    printf("Type something: ");
    fgets(S, 150, stdin);

    int stringLength = strlen(S) - 1;
    
    printf("Number between 1 and %i\n", stringLength);
    I = readLimitedInteger("Type: ", 1, stringLength);

    printf("\nNumber between %i and %i\n", I, stringLength);
    J = readLimitedInteger("Type: ", I, stringLength);

    char newString[150];
    int newStringLength = 0;

    for ( int x = I - 1; x < J; x++ ) {
        newString[newStringLength++] = S[x];
    }

    printf("\nNew string(Main String %ith character to %ith): %s\n", I, J, newString);

    return 0;
}