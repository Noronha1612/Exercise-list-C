#include "stdio.h"
#include "ctype.h"

/*
A sequência de Fibonacci é uma sequência infinita composta por números que obedecem o seguinte padrão: 0 1 1 2 3 5 8 13…
Como pode se ver, os dois primeiros números (0 1) quando somados dão origem ao terceiro (1). 
De modo que o n-ésimo número é fruto da soma dos dois anteriores.

Crie um programa que pede ao usuário um número X, e imprima o X-ésimo valor da sequência.
*/

int main() {

    int numberPlace, number = 0, nextNumber = 1, previewNumber;
    int allNumbers[255];
    
    while(1) {
        printf("Type X to see the Xth value on fibbonacci sequence: ");
        scanf("%i", &numberPlace);
        getchar();

        if( numberPlace > 0 ) break;
        printf("Type a valid value.\n"); 
    }

    allNumbers[0] = 0;

    for ( int currentNumberPlace = 1; currentNumberPlace < numberPlace; currentNumberPlace++ ) {
        previewNumber = number;
        number = nextNumber;
        nextNumber = number + previewNumber;
        
        allNumbers[currentNumberPlace] = number;
    }

    printf("\nThe number on place %ith is %i\n\n", numberPlace, number);

    char doesUserWantToSee;

    while(1) {
        printf("Do you want to see the sequence? [Y/N] ");
        doesUserWantToSee = tolower(getchar());
        getchar();

        if ( doesUserWantToSee == 'y' || doesUserWantToSee == 'n' ) break;
        printf("Type Y to yes or N to no.\n");
    }

    if ( doesUserWantToSee == 'y' ) {

        printf("\nSequence: ");

        for ( int currentNum = 0; currentNum < numberPlace; currentNum++ ) {
            printf("%i  ", allNumbers[currentNum]);
        }
        
        printf("\n");
    }

    printf("\nI apprecciate your company! :)\n\n");

    return 0;
}