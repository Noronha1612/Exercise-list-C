#include "stdio.h"
#include "ctype.h"

/*

Crie um algoritmo que simule o funcionamento de um caixa de supermercado. 
O caixa fica aberto até o fim do expediente e pode processar a compra de vários clientes.  
Cada cliente pode comprar vários itens 
(1.Feijão - R$ 2.0, 2.Arroz - R$ 1.5, 3.Carne - R$ 10.0, 4. Tomate - R$ 3.0, 5. Cebola - R$ 2.5). 
Ao ler cada item deve ser exibida uma mensagem para o operador do caixa perguntando se há mais itens a serem processados. 
Ao final, exiba quanto a compra custou ao cliente. E então solicite do operador do caixa a informação se deseja fechar o caixa.  
Quando o caixa for fechado, imprima quanto de dinheiro aquele caixa apurou no dia.

*/

char getAnswer(char* msg) {
    char value;

    while(1) {
        printf("%s", msg);
        value = tolower(getchar());
        getchar();

        if ( value == 'y' || value == 'n' ) break;
        printf("Type Y to Yes and N to No.\n");
    }

    return value;
}

int main() {

    float prices[5] = {
        2.0, // Feijão
        1.5, // Arroz
        10.0, // Carne
        3.0, // Tomate
        2.5 // Cebola
    };

    float total, clientTotal;

    while(1) {
        int code, quantity;

        printf("Codes:\n");
        printf("[1] Feijao - BRL %.2f\n", prices[0]);
        printf("[2] Arroz - BRL %.2f\n", prices[1]);
        printf("[3] Carne - BRL %.2f\n", prices[2]);
        printf("[4] Tomate - BRL %.2f\n", prices[3]);
        printf("[5] Cebola - BRL %.2f\n", prices[4]);

        while(1) {
            printf("Type the code: ");
            scanf("%i", &code);
            getchar();

            if ( code <= 5 && code >= 1 ) break;
            printf("Type a valid code");
        }

        while(1) {
            printf("Quantity: ");
            scanf("%i", &quantity);
            getchar();

            if ( quantity > 0 ) break;
            printf("Type a valid quantity.\n");
        }

        clientTotal += prices[code - 1] * quantity;

        char willClientBuyMore = getAnswer("There is something else? [Y/N]");

        if ( willClientBuyMore == 'y' ) continue;
        else {
            printf("\nClient must pay: BRL %.2f\n\n", clientTotal);

            total += clientTotal;
            clientTotal = 0;
        }

        char willClose = getAnswer("Will you close? [Y/N]");

        if ( willClose == 'y' ) break;
    }

    printf("\nYou collected BRL %.2f today!\n", total);

    return 0;
}