#include "stdio.h"
#include "stdlib.h"

/*

Ler nome, e idade, se idade maior ou igual a 18 anos, 
imprime o nome da pessoa e a frase “deve votar”, 
caso contrário imprimir “Não é obrigado a votar”.

*/

int main() {

    char* name = malloc(sizeof(char));
    int age;

    printf("What's your name? ");
    scanf("%s", name);
    getchar();

    while(1) {
        printf("%s, how old are you? ", name);
        scanf("%i", &age);
        getchar();

        if ( age >= 0 ) break;
        printf("Please, type a valid age.\n");
    }

    if ( age < 18 ) printf("\n%s, You are not forced to vote.\n", name);
    else printf("\n%s, You must vote.\n", name);
    

    return 0;
}