#include "stdio.h"
#include "string.h"
#include "ctype.h"

/*

Crie um programa que recebe uma string e um caractere, 
e apague (substitua por ‘ ’ (espaço)) todas as ocorrências desse caractere na string.

*/

int main() {

    char string[255];
    char character;

    printf("Type something: ");
    fgets(string, 255, stdin);

    printf("\nType a character: ");
    scanf("%c", &character);
    getchar();

    for ( int x = 0; x < strlen(string); x++ ) {
        if ( tolower(string[x]) == tolower(character) ) string[x] = ' ';
    }

    printf("String without \"%c\": %s", toupper(character), string);

    return 0;
}