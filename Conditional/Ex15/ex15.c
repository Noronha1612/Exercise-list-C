#include "stdio.h"

int readInteger(char* msg, int start, int end, char subject[255]) {

    int integer;

    while(1) {
        printf("%s", msg);
        scanf("%i", &integer);

        if( integer <= end || end == -1 && integer >= start ) break;
        printf("Type a valid %s.\n", subject);
    }

    return integer;
}

int main() {
    int age;

    age = readInteger("Type your age:", 0, -1, "age");

    if ( age < 18 ) {
        printf("\nUnfortunately, you are too young to buy.\n");
    }
    else {

        int drinkTypeCode, drinkOptionCode;

        printf("\nOptions:\n");
        printf("[1] Whisky\n");
        printf("[2] Vodka\n");
        printf("[3] Beer\n");
        printf("[4] Liquor\n");

        drinkTypeCode = readInteger("Pick your poison:", 1, 4, "option");

        char drinkTypes[4][40] = {
            "Whisky",
            "Vodka",
            "Beer",
            "Liquor"
        };

        float prices[4][3] = {
            { 200.0, 150.0, 140.0 },
            { 60.0, 40.0, 30.0 },
            { 1.5, 2.0, 3.0 },
            { 8.0, 20.0, 22.0 }
        };

        printf("\nChoose an option:\n");

        for( int option = 0; option <= 2; option++ ) {
            printf("[%i] %s%i - BRL %.2f\n", option + (drinkTypeCode * 100), drinkTypes[drinkTypeCode - 1], option + 1, prices[drinkTypeCode - 1][option]);
        }

        //printf("\n%i\n%i\n", drinkTypeCode * 100, (drinkTypeCode * 100) + 2);

        drinkOptionCode = readInteger("Your option:", drinkTypeCode * 100, (drinkTypeCode * 100) + 2, "option"); // Não está impondo limites por algum motivo

        float priceSingle = prices[drinkTypeCode - 1][drinkOptionCode - drinkTypeCode * 100];

        int quantity = readInteger("How many do you want:", 0, -1, "quantity");

        float discount = 0;

        if ( quantity >= 100 ) discount = 0.35;
        else if ( quantity >= 50 ) discount = 0.3;
        else if ( quantity >= 5 ) discount = 0.1;

        float totalWithoutDiscount = priceSingle * quantity;

        float total = totalWithoutDiscount - (discount * totalWithoutDiscount);

        printf("\nYou bought successfully %i \"%s %i\" and must pay BRL %.2f\n", quantity, drinkTypes[drinkTypeCode - 1], (drinkOptionCode - drinkTypeCode * 100) + 1, total);
    }

    return 0;
}