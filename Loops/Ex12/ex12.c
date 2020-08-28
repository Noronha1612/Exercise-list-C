#include "stdio.h"
#include "string.h"
#include "stdlib.h"

/*

Crie um jogo de adivinhação que deve ser jogado entre dois usuários.
O primeiro usuário deve digitar três caracteres distintos.
O segundo usuário deve digitar uma tecla na tentativa de acertar um dos três caracteres. 
Caso a tecla digitada esteja correta, 
imprima uma mensagem informando que ele acertou e quantos caracteres restam para ele acertar. 
Caso ele erre, imprima na tela e informe quantos caracteres restam e o número de tentativas restantes 
(o usuário só pode digitar no máximo 15 caracteres). 
O jogo termina quando o usuário acerta todos os caracteres ou quando não possui mais tentativas.

*/

int main() {

    int wordLength;

    while(1) {
        printf("How much letters will have the word? ");
        scanf("%i", &wordLength);
        getchar();

        if ( wordLength >= 3 ) break;
        printf("Minimum: 3 characters\n");
    }

    char word[wordLength];
    
    while(1) {
        printf("Type %i characters: ", wordLength);
        scanf("%s", word);
        getchar();

        if ( strlen(word) == wordLength ) break;
        printf("The word must have exactly %i characters.\n", wordLength);
    }
    

    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");
    #endif

    int userShootsLeft = 15;

    int charHasBeenFound[wordLength]; // Vetor com 0 para cada letra da palavra e quando a letra for acertada, o 0 correspondente vai virar 1

    for ( int x = 0; x < wordLength; x++ ) {
        charHasBeenFound[x] = 0;
    }

    int didUserWin = 0;

    char charsShooted[255] = "";

    while(userShootsLeft != 0) {
        char shoot;

        printf("\nShoots left: %i\n", userShootsLeft);

        printf("Status: ");

        for ( int x = 0; x < wordLength; x++) {
            if ( charHasBeenFound[x] ) printf("%c ", word[x]);
            else printf("_ ");
        }

        printf("\n");

        printf("Shoot: ");
        shoot = getchar();
        getchar();

        int didUserShootedLetterPrevious = 0;

        for ( int x = 0; x < strlen(charsShooted); x++ ) {
            if ( charsShooted[x] == shoot ) didUserShootedLetterPrevious = 1;
        }

        if ( didUserShootedLetterPrevious ) {
            printf("You have already shooted that char previous.\n");
            continue;
        }

        int wordIncludesLetter = 0, charPlace = -1;

        for ( int x = 0; x < wordLength; x++ ) {
            if ( word[x] == shoot ) {
                wordIncludesLetter = 1;
                charPlace = x;
            }
        }

        charsShooted[strlen(charsShooted)] = shoot;

        if ( wordIncludesLetter ) {
            printf("You found one!\n");
            charHasBeenFound[charPlace] = 1;
        }
        else {
            userShootsLeft--;
            printf("You missed...\n");
        }

        int everyCharHasBeenFound = 1;

        for ( int x = 0; x < wordLength; x++ ) {
            if ( charHasBeenFound[x] == 0 ) everyCharHasBeenFound = 0;
        }

        if ( everyCharHasBeenFound ) {
            didUserWin = 1;
            break;
        }
    }

    if ( didUserWin ) {
        printf("\nYou found the word: \"%s\". Congratulations!!!\n", word);
    }
    else {
        printf("\nYou couldn't find the word: \"%s\". Good luck next time!\n", word);
    }

    return 0;
}