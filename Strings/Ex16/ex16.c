#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"

/*

O jogo da forca é um jogo em que o jogador tem que acertar qual é a palavra proposta, 
tendo como dica o número de letras e o tema ligado à palavra. 
A cada letra errada, o usuário perde uma tentativa (o número é determinado pelo programador). 
O jogo termina ou com o acerto da palavra ou com o término do número de tentativas.

Para começar o jogo se imprime um underline correspondente ao lugar de cada letra.
Por exemplo, para a palavra "AMOR", se escreve:
A M O R ------> _ _ _ _

O jogador que tenta adivinhar a palavra deve ir dizendo as letras que podem existir na palavra. 
Cada letra que ele acerta é escrita no espaço correspondente.

A M O R→ A _ O R

Caso a letra não exista nessa palavra, imprime-se que a letra está incorreta, 
e reduz-se o número de tentativas.

*/

char showMenu(int shootsLeft, char* word, int* positions, char* validLetters, char* alreadyShot, int counterAlreadyShot) {
    printf("Shoots left: %i\n", shootsLeft);
    printf("Word: ");

    for ( int x = 0; x < strlen(word); x++ ) {
        if ( positions[x] ) printf("%c ", toupper(word[x]));
        else printf("_ ");
    }
    printf("\n");

    char shoot;

    while(1) {
        printf("Shoot: ");
        scanf("%c", &shoot);
        getchar();

        int isValid = 0;

        for ( int x = 0; x < 26; x++ ) {
            if ( tolower(shoot) == validLetters[x] ) isValid = 1;
        }

        int hasAlreadyShot = 0;

        for ( int x = 0; x < counterAlreadyShot; x++ ) {
            if ( tolower(alreadyShot[x]) == tolower(shoot) ) hasAlreadyShot = 1;
        }

        if ( isValid && !hasAlreadyShot ) break;
        else if ( !isValid )printf("Type a letter.\n");
        else printf("You have already shot that letter.\n");
    }

    return tolower(shoot);
}

int insertIfNotExist(char* string, char shoot, int counter) {
    int alreadyExist = 0;

    for ( int x = 0; x < counter; x++ ) {
        if ( tolower(string[x]) == tolower(shoot) ) alreadyExist = 1;
    }

    if ( !alreadyExist ) {
        string[counter] = shoot;
        return 1;
    }
    return 0;
}

int main() {

    const char validLetters[26] = "abcdefghijklmnopqrstuvwxyz";

    char* word = malloc(sizeof(char));

    while(1) {
        printf("Main word: ");
        scanf("%s", word);
        getchar();

        int allValidLetters = 1;

        for ( int x = 0; x < strlen(word); x++ ) {
            int isValid = 0;

            for ( int y = 0; y < 26; y++ ) {
                if ( tolower(word[x]) == validLetters[y] ) isValid = 1;
            }

            if ( !isValid ) allValidLetters = 0;
        }

        if ( strlen(word) <= 10 && allValidLetters ) break;
        else if ( strlen(word) > 10 )printf("Maximum length exceed(10 letters).\n");
        else printf("Only letters will be accepted.\n");
    }

    int shootsLeft = 7;

    int positions[strlen(word)];
    for ( int x = 0; x < strlen(word); x++ ) {
        positions[x] = 0;
    }

    int didUserWin = 0;

    char alreadyShot[26];
    int counterAlreadyShot = 0;

    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");
    #endif

    while(1) {
        char shoot = showMenu(shootsLeft, word, positions, validLetters, alreadyShot, counterAlreadyShot);
        
        #ifdef _WIN32
            system("cls");
        #else 
            system("clear");
        #endif

        int charFound = 0;

        for ( int x = 0; x < strlen(word); x++ ) {
            if ( tolower(word[x]) == shoot ) {
                positions[x] = 1;
                charFound = 1;
            }
        }

        if ( !charFound ) {
            shootsLeft--;

            if ( shootsLeft == 0 ) break;

            int didInsert = insertIfNotExist(alreadyShot, shoot, counterAlreadyShot);

            if ( didInsert ) counterAlreadyShot++;

            printf("You missed...\n\n");
        }
        else {
            int allPositionsFound = 1;

            for ( int x = 0; x < strlen(word); x++ ) {
                if ( positions[x] == 0 ) allPositionsFound = 0;
            }

            if ( allPositionsFound ) {
                didUserWin = 1;
                break;
            }

            int didInsert = insertIfNotExist(alreadyShot, shoot, counterAlreadyShot);

            if ( didInsert ) counterAlreadyShot++;

            printf("You hit!\n\n");
        }
    }

    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");
    #endif

    if ( didUserWin ) {
        printf("Congrats!! You found successfully the word: ");
    }
    else {
        printf("Ooops... You couldn't find the word: ");
    }

    for ( int x = 0; x < strlen(word); x++ ) {
        printf("%c", toupper(word[x]));
    }

    printf("\n\n");

    return 0;
}