#include <stdio.h>

int main() {
    double salary, multiplier, newSalary;

    printf("Type the employee salary: USD");
    scanf("%lf", &salary);

    if ( salary <= 1000 ) {
        multiplier = 1.2;
    }
    else {
        multiplier = 1.1;
    }

    newSalary = salary * multiplier;

    printf("\nThe employee new salary is equal to USD%.2f", newSalary);

    return 0;
}