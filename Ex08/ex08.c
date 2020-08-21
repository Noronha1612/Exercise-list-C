#include "stdio.h"

int main() {
    int days;

    while(1) {
        // Dúvida, quando dado um caractere vazio entra em um loop infinito.

        printf("Type how many days did the guest stay:");
        scanf("%i", &days);

        if ( days > 0 ) break;
        printf("Type a valid days quantity\n");
    }

    double fixedMoney = days * 50;

    double variableMoneyMultiplier;

    if ( days < 15 ) variableMoneyMultiplier = 15.3;
    else if ( days == 15 ) variableMoneyMultiplier = 10;
    else variableMoneyMultiplier = 8.5;

    double variableMoney = variableMoneyMultiplier * days;

    double totalMoney = variableMoney + fixedMoney;

    printf("\nTotal cost: USD %.2lf\n", totalMoney);

    return 0;
}