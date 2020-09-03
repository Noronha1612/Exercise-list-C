#include "stdio.h"
#include "string.h"

/*

Crie um programa que compara duas strings. 
Imprima ‘Eh igual’, se o valor das duas strings for igual. 
Caso contrário, imprima “Nao eh igual”.

*/

int main() {
    char text1[255], text2[255];

    printf("Type the first text: ");
    fgets(text1, 255, stdin);
    
    printf("Type the second text: ");
    fgets(text2, 255, stdin);

    if ( !strcmp(text1, text2) ) printf("\nBoth text are the same.\n");
    else printf("\nThe texts are not equal.\n");

    return 0;
}