#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

/*

Crie uma programa que lê uma string e um caractere, 
e retorne o número de vezes que esse caractere aparece na string.

*/

int main() {

    char string[255];
    char character;

    printf("Type something: ");
    fgets(string, 255, stdin);

    printf("\nNow, type a character: ");
    scanf("%c", &character);
    getchar();

    int counterTimes = 0;

    for ( int x = 0; x < strlen(string); x++ ) {
        if ( tolower(string[x])  == tolower(character) ) counterTimes++;
    }

    printf("\nThe char \"%c\" was found %i times on \"%s\".\n", toupper(character), counterTimes, string);

    return 0;
}