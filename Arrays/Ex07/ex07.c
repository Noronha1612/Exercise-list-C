#include "stdio.h"
#include "math.h"

/*

Escrever um programa que
(a) leia um conjunto de 10 notas, armazenando-as em vetor,
(b) calcule e imprima a sua média,
(c) calcule e imprima o número de alunos com nota superior à média

*/

void readGradeArray(float gradeArr[]) {
    for ( int x = 0; x < 10; x++ ) {
        float element;

        while(1) {
            printf("Type %i grade: ", x + 1);
            scanf("%f", &element);
            getchar();

            if ( element >= 0 && element <= 10 ) break;
            printf("Type a valid grade.\n");
        }
        
        gradeArr[x] = element;    
    }
}

int main() {

    float grades[10];
    readGradeArray(grades);

    float sumGrades = 0;
    int amountApproved = 0;

    for( int x = 0; x < 10; x++ ) {
        sumGrades += grades[x];

        if ( grades[x] >= 7 ) amountApproved++;
    }

    float gradesAverage = sumGrades / 10;

    printf("\nResult:\n");
    
    printf("Grades average: ");
    fmodf(gradesAverage, 1) == 0 ?
    printf("%i\n", (int) gradesAverage) :
    printf("%.2f\n", gradesAverage) ;

    printf("Amount approved: %i\n", amountApproved);

    return 0;
}