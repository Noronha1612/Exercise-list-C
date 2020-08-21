#include "stdio.h"

float readGrade(char* msg) {
    float grade;

    while(1) {
        printf("%s", msg);
        scanf("%f", &grade);

        if ( grade >= 0 && grade <= 10 ) break;
        printf("Type a valid grade.\n");
    }

    return grade;
}

int main() {

    float grade1, grade2, grade3;

    grade1 = readGrade("Type the first grade:");
    grade2 = readGrade("Type the second grade:");
    grade3 = readGrade("Type the Third grade:");

    float average = (grade1 + grade2 + grade3) / 3;

    printf("The student's average is equal to %.1f", average);

    return 0;
}