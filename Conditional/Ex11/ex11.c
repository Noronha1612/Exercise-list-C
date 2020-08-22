#include "stdio.h"

int main() {

    int option;

    char operators[4] = { '+', '-', '/', '*' };

    printf("Calculator\n");
    printf("Please select an option\n");
    printf("[1] +\n");
    printf("[2] -\n");
    printf("[3] /\n");
    printf("[4] *\n");

    while(1) {
        printf("Your option:");
        scanf("%i", &option);

        if ( option <= 4 && option >= 1 ) break;
        printf("Please select a valid option.\n");
    }

    float num1, num2, result;

    printf("Type the first number value:");
    scanf("%f", &num1);

    printf("Type the second number value:");
    scanf("%f", &num2);

    if ( option == 1 ) result = num1 + num2;
    else if ( option == 2 ) result = num1 - num2;
    else if ( option == 3 ) result = num1 / num2;
    else result = num1 * num2;

    printf("%.2f %c %.2f = %.2f", num1, operators[option - 1], num2, result);

    return 0;
}