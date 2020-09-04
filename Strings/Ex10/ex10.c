#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

/*

Fazer um programa que:
(a) leia uma frase de 80 caracteres, incluindo brancos,
(b) conte e imprima quantos brancos existem na frase,
(c) conte e imprima quantas vezes a letra ‘a’ aparece,
(d) substitua as vogais pelo caracter ‘X’.

*/

int main() {

    char phrase[80];
    char vowels[5] = "aeiou";

    printf("Type a phrase (Maximum 80 characters): ");
    fgets(phrase, 80, stdin);

    int counterSpace = 0, counterA = 0;

    for ( int x = 0; x < strlen(phrase); x++ ) {
        char element = phrase[x];

        if ( element == ' ' ) counterSpace++;
        if ( tolower(element) == 'a' ) counterA++;

        int isElementVowel = 0;

        for ( int y = 0; y < 5; y++ ) {
            if ( tolower(element) == vowels[y] ) isElementVowel = 1;
        }

        if ( isElementVowel ) phrase[x] = 'X';
    }

    printf("\nHow many spaces: %i\n", counterSpace);
    printf("How many \"A\"s: %i\n", counterA);
    printf("Phrase with all vowels replaced by 'X': %s\n", phrase);

    return 0;
}