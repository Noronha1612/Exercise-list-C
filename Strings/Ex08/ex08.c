#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "ctype.h"
#include "string.h"

/*

Crie um programa que pede ao usuário o tamanho do texto que deseja digitar. 
Em seguida, o programa pede ao usuário que digite um texto. 
O programa deve transformar alguns dos caracteres em maiúsculos, 
outros em minúsculos e outros permanecem como estão. 
Para isso, você deve navegar por cada caracter do texto, e gerar um número aleatório 0 ou 1. 
Se o número gerado for 0, o caracter atual é convertido para minúsculo, se o número for 1, 
o caracter é convertido para maiúsculo. Imprima o texto resultante.

*/

int readLength(char* msg) {
    int length;

    while(1) {
        printf("%s", msg);
        scanf("%i", &length);
        getchar();

        if ( length > 0 ) break;
        printf("Type a valid length.\n");
    }

    return length;
}

int main() {

    int length = readLength("How many characters will you type? ");

    char text[length];
    
    printf("Type the text: ");
    fgets(text, length + 1, stdin);

    srand(time(NULL));

    for ( int x = 0; x < length; x++ ) {
        int letterSize = rand() % 2;

        if ( letterSize == 1 ) text[x] = toupper(text[x]);
        else if ( letterSize == 2 ) text[x] = tolower(text[x]);
    }

    printf("\nNewer text: %s\n", text);

    return 0;
}