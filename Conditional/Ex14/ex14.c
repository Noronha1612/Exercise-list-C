#include "stdio.h"
#include "ctype.h"

int readLimitedInteger(char* msg, int max, int min) {
    int value;

    while(1) {
        printf("%s", msg);
        scanf("%i", &value);

        if ( value >= min && value <= max || max == -1 ) break;
        printf("Type a valid value\n");
    }

    return value;
};

int main() {
    float total = 0;

    while(1) {
        char items[6][40] = {
            "Hot Dog",
            "Simple Bauru",
            "Bauru with eggs",
            "Hamburguer",
            "Cheeseburguer",
            "Soda"
        };

        float codeAndPrice[6][2] = {
            {100, 1.2},
            {101, 1.3},
            {102, 1.5},
            {103, 1.2},
            {104, 1.3},
            {105, 1},
        };

        printf("\nMenu\n");

        for (int item = 0; item <= 5; item++) {
            printf("[%.0f] %s\n", codeAndPrice[item][0], items[item]);
        }

        int option, quantity;

        option = readLimitedInteger("Select an option:", 105, 100);
        quantity = readLimitedInteger("How many do you want?", -1, 0);
        getchar(); // Necessário por algum motivo.

        total = total + (codeAndPrice[option - 100][1] * quantity);

        char wantToBuyMore;

        while(1) {
            printf("Do you want to buy something else? [Y/N]");
            scanf("%c", &wantToBuyMore); //getchar() não funcionando nesse caso

            wantToBuyMore = tolower(wantToBuyMore);

            if ( wantToBuyMore == 'y' || wantToBuyMore == 'n' ) break;
            printf("Select a valid option!\n");
        }

        if ( wantToBuyMore == 'n' ) break;
    }

    printf("\nYou must pay USD %.2f\n", total);

    printf("\nWe appreciate your company!\n");

    return 0;
}