#include "stdio.h"
#include "string.h"
#include "ctype.h"

/*

Digite um nome, calcule e retorne quantas letras tem esse nome

*/

int main() {

    char name[100];

    printf("Name: ");
    fgets(name, 100, stdin);
    
    char validLetters[26] = "abcdefghijklmnopqrstuvwxyz";

    int counterLetters = 0;

    for ( int x = 0; x < strlen(name); x++ ) {
        int isElementLetter = 0;

        for ( int y = 0; y < 26; y++ ) {
            if ( tolower(name[x]) == tolower(validLetters[y]) ) isElementLetter = 1;
        }

        if ( isElementLetter ) counterLetters++;
    }

    printf("\nThe name contains %i letters.\n", counterLetters);

    return 0;
}