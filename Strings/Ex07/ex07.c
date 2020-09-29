#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

/*

Receber uma palavra, calcule quantas vogais (a, e, i, o, u) possui essa palavra. 
Entre com um caractere (vogal ou consoante) e 
substitua todas as vogais da palavra dada por esse caractere.

*/

int main() {

    char vowels[5] = "aeiou";
    char allLetters[26] = "abcdefghijklmnopqrstuvwxyz";

    char* word = malloc(sizeof(char));
    char character;

    printf("Type a word: ");
    scanf("%s", word);
    getchar();

    printf("\n");

    while(1) {
        printf("Type a letter: ");
        scanf("%c", &character);
        getchar();

        int isValid = 0;

        for ( int x = 0; x < 26; x++ ) {
            if ( allLetters[x] == tolower(character) ) isValid = 1;
        }

        if ( isValid ) break;
        printf("Type a valid letter\n");
    }

    for ( int x = 0; x < strlen(word); x++ ) {
        int isVowel = 0;

        for ( int y = 0; y < 5; y++ ) {
            if ( tolower(word[x]) == vowels[y] ) isVowel = 1;
        }

        if ( isVowel ) word[x] = character;
    }

    printf("\nWord with all vowers replaced by \"%c\": %s\n", character, word);

    return 0;
}