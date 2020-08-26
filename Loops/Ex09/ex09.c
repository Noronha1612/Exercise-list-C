#include "stdio.h"

/*
Criar um programa que apresenta o seguinte menu:
BOAS VINDAS:
1– Imprimir “Olá!”;
2– Imprimir “Bem vindo!”;
3– Sair do algoritmo;
Se o usuário digitar a opção 1 ou 2, a respectiva mensagem é impressa. 
Em seguida, o menu é impresso novamente para que o usuário faça uma nova escolha. 
O programa só é encerrado quando o usuário digitar 3 para sair.

*/

int main() {

    while(1) {
        int option;

        printf("Welcome:\n");
        printf("[1] Print \"Hello!\"\n");
        printf("[2] Print \"Welcome!\"\n");
        printf("[3] Leave the algorithm\n");

        while(1) {
            printf("Your option:");
            scanf("%i", &option);
            getchar();

            if ( option <= 3 && option >= 1 ) break;

            printf("Select a valid option\n");
        }

        if ( option == 3 ) break;
        else if ( option == 1 ) {
            printf("\nHello!\n\n");
        }
        else  {
            printf("\nWelcome!\n\n");
        }
    }

    printf("\nI appreciate your company :)\n");
    
    return 0;
}