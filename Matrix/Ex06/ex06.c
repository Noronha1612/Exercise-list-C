#include "stdio.h"
#include "math.h"

/*

6- Faça um programa que leia os nomes de 5 alunos. Além disso, 
leia uma matriz de 5 linhas e 4 colunas contendo as seguintes informações sobre cada aluno, 
sendo todas as informações do tipo inteiro:

Primeira coluna: número de matrícula (use um inteiro)

Segunda coluna: média das provas

Terceira coluna: média dos trabalhos

Quarta coluna: nota final

Elabore um programa que:

Leia os nomes de cada aluno

Leia as três primeiras informações de cada aluno

Calcule a nota final como sendo a soma da média das provas e da média dos trabalhos

Imprima o nome, a matrícula e a nota final do aluno que obteve a maior nota final 
(assuma que só existe uma maior nota)

Imprima a média aritmética das notas finais

*/

void readStudentsData(int student[4]) {

    int registration, gradeAverage, workAverage, finalGrade;

    printf("Registration: ");
    scanf("%i", &registration);

    while(1) {
        printf("Grade average: ");
        scanf("%i", &gradeAverage);

        if ( gradeAverage >= 0 && gradeAverage <= 5 ) break;
        printf("Max average length: 5\n");
    }

    while(1) {
        printf("Work average: ");
        scanf("%i", &workAverage);

        if ( workAverage >= 0 && workAverage <= 5 ) break;
        printf("Max average length: 5\n");
    }
    
    finalGrade = gradeAverage + workAverage;

    student[0] = registration;
    student[1] = gradeAverage;
    student[2] = workAverage;
    student[3] = finalGrade;
}

int main() {

    int students[5][4];

    for ( int x = 0; x < 5; x++ ) {
        printf("\nStudent %i data:\n", x + 1);
        readStudentsData(students[x]);
    }

    int bestStudent = -1;
    int biggestFinalGrade = -1;
    int bestStudentRegistration = -1;

    int gradesSum = 0;

    for ( int x = 0; x < 5; x++ ) {
        if ( students[x][3] > biggestFinalGrade || biggestFinalGrade == -1 ) {
            bestStudent = x;
            biggestFinalGrade = students[x][3];
            bestStudentRegistration = students[x][0];
        }

        gradesSum += students[x][3];
    }

    float gradesAverage = (float)gradesSum / 5;

    printf("\nResult:\n");
    printf("Student with the biggest final grade: Student %i - %i (grade: %i)\n", bestStudent + 1, bestStudentRegistration, biggestFinalGrade);
    printf("Grade average: ");

    fmodf(gradesAverage, 1) == 0 ? 
    printf("%i\n", (int) gradesAverage) : 
    printf("%.2f\n", gradesAverage);
    return 0;
}