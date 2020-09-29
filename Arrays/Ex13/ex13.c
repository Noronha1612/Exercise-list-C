#include "stdio.h"
#include "stdlib.h"

/*

Um sistema de controle de estoque armazena o código (inteiro), 
a quantidade em estoque (inteiro) e o preço unitário (float) das mercadorias. 
Fazer um programa que exiba um menu com as seguintes opções:

MENU
1 - Cadastrar mercadoria
2 - Consultar mercadoria
3 - Valor total em mercadorias
4 - Sair

Inicialmente não há nenhuma mercadoria cadastrada. 
A primeira opção permitirá que o usuário cadastre uma 
nova mercadoria informando todos os dados citados anteriormente.

A segunda opção permitirá que o usuário consulte o cadastro, informando o código da mercadoria.

A terceira opção permitirá a consulta do valor total do estoque, 
levando em conta todas as mercadorias cadastradas.

A quarta opção permitirá o término do programa.

*/

int readLimitedInteger(char* msg, int min, int max, char* subject) {
    int value;

    while (1) {
        printf("%s", msg);
        scanf("%i", &value);
        getchar();

        if ( value >= min && (value <= max || max == -1) ) break;
        printf("Type a valid %s!\n", subject);
    }

    return value;
}


int showMenu() {
    printf("\nMenu:\n");
    printf("[1] Register product\n");
    printf("[2] Consult product\n");
    printf("[3] Total value in products\n");
    printf("[4] Leave program\n");

    int code = readLimitedInteger("Option:", 1, 4, "option");

    return code;
}


void registerProduct(int *codes, int *quantity, float *prices, int index) {
    int code, qtt;
    float unitPrice;

    code = readLimitedInteger("Product code: ", 0, -1, "code");
    qtt = readLimitedInteger("Quantity: ", 0, -1, "quantity");

    while(1) {
        printf("Price by unit: USD ");
        scanf("%f", &unitPrice);
        getchar();

        if ( unitPrice > 0 ) break;
        printf("Type a valid price!\n");
    }

    codes[index] = code;
    quantity[index] = qtt;
    prices[index] = unitPrice;
}


void consultProduct(int *codes, int *quantity, float *prices, int allProductsLength) {
    if ( allProductsLength == 0 ) {
        printf("There is no item to be searched.\n");
        return;
    }

    printf("Codes available:");

    for ( int x = 0; x < allProductsLength; x++ ) {
        printf(" %i", codes[x]);
    }

    printf("\n");

    int searchedCode = readLimitedInteger("Item code:", 0, -1, "code");
    int itemIndex;

    int hasItemExist = 0;

    for ( int x = 0; x < allProductsLength; x++ ) {
        if ( codes[x] == searchedCode ) {
            hasItemExist = 1;
            itemIndex = x;
        }
    }

    if ( !hasItemExist ) {
        printf("Code not found...\n");
        return;
    }

    printf("\nCode: %i\n", searchedCode);
    printf("Quantity: %i\n", quantity[itemIndex]);
    printf("Price by unit: USD %.2f\n", prices[itemIndex]);
    printf("Total price: USD %.2f\n", prices[itemIndex] * quantity[itemIndex]);
}


void totalValue(int *quantity, float *prices, int allProductsLength) {
    float total = 0;

    for ( int x = 0; x < allProductsLength; x++ ) {
        int qtt = quantity[x];
        float price = prices[x];

        total += price * qtt;
    }

    printf("Total value in stock: USD %.2f\n", total);
}


int main() {

    int *itemCodes = malloc(sizeof(int));
    int *itemQuantity = malloc(sizeof(int));
    float *itemPrices = malloc(sizeof(float));

    int counterItems = 0;

    while(1) {
        int code = showMenu();
        printf("\n");

        #ifdef _WIN32
            system("cls");
        #else 
            system("clear");
        #endif

        if ( code == 1 ) registerProduct(itemCodes, itemQuantity, itemPrices, counterItems++);
        else if ( code == 2 ) consultProduct(itemCodes, itemQuantity, itemPrices, counterItems);
        else if ( code == 3 ) totalValue(itemQuantity, itemPrices, counterItems);
        else break;
    }

    printf("\nProgram closed!\n");

    return 0;
}