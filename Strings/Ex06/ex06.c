#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*

Receba uma palavra e imprima de trás-para-frente.

*/

int main() {

    char* word = malloc(sizeof(char));

    printf("Type a word: ");
    scanf("%s", word);

    printf("\nReverse word: ");

    for ( int x = strlen(word) - 1; x >= 0; x-- ) {
        printf("%c", word[x]);
    }

    printf("\n");

    return 0;
}