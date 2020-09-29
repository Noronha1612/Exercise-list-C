#include "stdio.h"
#include "math.h"

int readPositiveInteger(char* msg, int min) {
    int value;

    while(1) {
        printf("%s", msg);
        scanf("%i", &value);

        if ( value >= min ) break;
        printf("Type a valid value.\n");
    }

    return value;
}

int main() {
    int sumChilds = 0, sumMoreThan2Childs = 0;
    float sumSalary = 0, biggestSalary = 0, lowestSalary = 0;
    
    int surveyQuantity = readPositiveInteger("How many peoples joined the survey?", 1);

    for ( int interviewed = 0; interviewed < surveyQuantity; interviewed++ ) {
        printf("\nInterviewed %i, please answer:\n", interviewed + 1);

        int childsQuantity = readPositiveInteger("How many childs do you have?", 0);
        float salary;

        while(1) {
            printf("How much do you earn by year? USD");
            scanf("%f", &salary);

            if ( salary >= 0 ) break;
            printf("Type a valid quantity.\n"); 
        }

        if ( salary > biggestSalary || biggestSalary == 0 ) biggestSalary = salary;
        if ( salary < lowestSalary || lowestSalary == 0 ) lowestSalary = salary;
        if ( childsQuantity >= 2 ) sumMoreThan2Childs = sumMoreThan2Childs + 1;
        sumChilds = sumChilds + childsQuantity;
        sumSalary = sumSalary + salary;
    }

    float salaryAverage = sumSalary / surveyQuantity;
    float childsAverage = (float)sumChilds / (float)surveyQuantity;
    float moreThan2ChildsPercentage = (float)sumMoreThan2Childs / (float)surveyQuantity;

    printf("\nSurver result:\n");

    printf("Salary average: USD");
    fmodf(salaryAverage, 1) == 0 ? 
    printf("%i\n", (int) salaryAverage) :
    printf("%.2f\n", salaryAverage);

    printf("Childs average: ");
    fmodf(childsAverage, 1) == 0 ? 
    printf("%i\n", (int) childsAverage) :
    printf("%.2f\n", childsAverage);

    printf("Biggest salary: USD %.2f\n", biggestSalary);

    printf("Lowest salary: USD %.2f\n", lowestSalary);

    printf("Percentage of interviewed with 2 or more childs: ");
    fmodf(moreThan2ChildsPercentage, 1) == 0 ?
    printf("%i%%\n", (int) moreThan2ChildsPercentage) :
    printf("%.2f%%\n", moreThan2ChildsPercentage);

    return 0;
}