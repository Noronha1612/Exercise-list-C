#include "stdio.h"

float readGrade(char* msg) {
    float value;

    while(1) {
        printf("%s", msg);
        scanf("%f", &value);

        if ( value <= 10 && value >= 0 ) break;
        printf("Type a valid grade!\n");
    }

    return value;
}

int main() {

    float grade1, grade2, finalGrade;

    grade1 = readGrade("Type the first grade:");
    grade2 = readGrade("Type the second grade:");
    finalGrade = readGrade("Type the final grade:");

    float average = (grade1 + grade2 + finalGrade) / 3;

    if ( average >= 7 ) {
        printf("\nAPPROVED\n");
    }
    else if ( average <= 4 ) {
        printf("\nDISAPPROVED\n");
    }
    else {

        printf("\nRECOVERY TEST\n");

        float recoveryGrade = readGrade("Type the recovery grade:");

        float recoveryAverage = (recoveryGrade + finalGrade) / 2;

        if ( recoveryAverage >= 5 ) {
            printf("\nAPPROVED WITH RECOVERY\n");
        }
        else {
            printf("\nDISAPPROVED\n");
        }
    }

    return 0;
}