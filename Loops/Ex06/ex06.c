#include "stdio.h"
#include "math.h"

/**
    6- Faça um programa que leia de forma indefinida vários números, calcule e mostre:
        (a) A soma dos números digitados
        (b) A quantidade de números digitados
        (c) A média dos números digitados
        (d) O maior número digitado
        (e) O menor número digitado
        (f) A média dos números pares
    Finalize a entrada de dados caso o usuário informe o valor 0.
*/

int main() {

    int counter = 0, counterEven = 0;
    float biggest = 0, lowest = 0, sumEven = 0, sumTotal = 0;

    while(1) {
        float num;

        printf("Type a number: (0 to stop) ");
        scanf("%f", &num);
        getchar();

        if ( num == 0 ) break;

        sumTotal = sumTotal + num;
        counter++;
        if ( fmodf(num, 2) == 0 ) {
            sumEven = sumEven + num;
            counterEven++;
        }
        if ( biggest == 0 || num > biggest ) biggest = num;
        if ( lowest == 0 || num < lowest ) lowest = num;
    }

    float numAverage = sumTotal / counter;
    float evenAverage = sumEven / counterEven;

    printf("\nResult:\n");

    printf("a) Total sum: ");
    fmodf(sumTotal, 1) == 0 ? 
    printf("%i\n", (int) sumTotal) :
    printf("%.2f\n", sumTotal);

    printf("b) Quantity of numbers: %i\n", counter);

    printf("c) Total average: ");
    fmodf(numAverage, 1) == 0 ? 
    printf("%i\n", (int) numAverage) :
    printf("%.2f\n", numAverage);

    printf("d) The biggest number: ");
    fmodf(biggest, 1) == 0 ? 
    printf("%i\n", (int) biggest) :
    printf("%.2f\n", biggest);

    printf("e) The lowest number: ");
    fmodf(lowest, 1) == 0 ? 
    printf("%i\n", (int) lowest) :
    printf("%.2f\n", lowest);

    printf("f) Even average: ");
    fmodf(evenAverage, 1) == 0 ? 
    printf("%i\n", (int) evenAverage) :
    printf("%.2f\n", evenAverage);

    return 0;
}