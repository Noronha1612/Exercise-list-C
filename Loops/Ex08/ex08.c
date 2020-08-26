#include "stdio.h"

/*

Desenvolva um sistema de verificação do usuário. 
Para isso, crie uma variável inteira chamada de senha e atribua a ela um número inteiro de 4 dígitos.
O programa deve pedir ao usuário uma senha, e verificar se a senha condiz com o valor armazenado na variável senha.
Se a senha digitada não estiver correta, imprima “Senha Incorreta” e solicite novamente a senha. Se a senha digitada for a correta,
deverá ser apresentada a mensagem “Senha Correta”. Vale salientar que o usuário só possui 3 tentativas para acertar a senha. 
Caso não acerte, deve ser impresso “acesso bloqueado”.

*/

int main() {

    int password = 8423, trysLeft = 3, didPasswordsMatch = 0;

    while(1) {
        int userPassword;

        printf("Type the password: ");
        scanf("%i", &userPassword);
        getchar();

        if ( userPassword == password ) {
            didPasswordsMatch = 1;
            break;
        }

        trysLeft--;

        if ( trysLeft == 0 ) break;

        printf("Incorrect password, try again.\n");
    }

    if ( didPasswordsMatch ) {
        printf("\nAccess granted!\n");
    }
    else {
        printf("\nAccess denied!\n");
    }

    return 0;
}