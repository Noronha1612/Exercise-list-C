#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

/*

Escreva um programa que leia um número N de palavras e diga qual das palavras é a 
primeira e a última na ordem alfabética.

*/

int main() {

    int manyWords;

    const char letters[26] = "abcdefghijklmnopqrstuvwxyz";

    while(1) {
        printf("How many words would you like to type? ");
        scanf("%i", &manyWords);
        getchar();

        if ( manyWords > 0 ) break;
        printf("Type a valid quantity.\n");
    }

    char first[50] = "";
    char last[50] = "";

    for ( int x = 0; x < manyWords; x++ ) {
        char word[50];

        while(1) {
            printf("Type the %ith word: ", x + 1);
            scanf("%s", word);
            getchar();

            if ( strlen(word) != 0 ) break;
            printf("Cannot be empty.\n");
        }

        int isFirst = 0, isLast = 0;

        if ( strlen(first) == 0 ) strcpy(first, word);
        if ( strlen(last) == 0 ) strcpy(last, word);

        for ( int y = 0; y < strlen(first); y++ ) {
            if ( word[y] != first[y] ) {
                int indexLetterFirst, indexLetterWord;

                for ( int z = 0; z < 26; z++ ) {
                    if ( letters[z] == tolower(word[y]) ) indexLetterWord = z;
                    if ( letters[z] == tolower(first[y]) ) indexLetterFirst = z;
                }

                if ( indexLetterWord < indexLetterFirst ) strcpy(first, word);

                break;
            }
        }

        for ( int y = 0; y < strlen(last); y++ ) {
            if ( word[y] != last[y] ) {
                int indexLetterLast, indexLetterWord;

                for ( int z = 0; z < 26; z++ ) {
                    if ( letters[z] == tolower(word[y]) ) indexLetterWord = z;
                    if ( letters[z] == tolower(last[y]) ) indexLetterLast = z;
                }

                if ( indexLetterWord > indexLetterLast ) strcpy(last, word);

                break;
            }
        }
    }

    printf("\nResult:\n");
    printf("First word: %s\n", first);
    printf("Last word: %s\n", last);

    return 0;
}