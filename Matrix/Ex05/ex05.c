#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "ctype.h"

/*

Leia uma matriz 5 x10 que se refere respostas de 10 questões de múltipla escolha, 
referentes a 5 alunos. Leia também um vetor de 10 posições contendo o gabarito de respostas 
que podem ser a, b, c ou d. Seu programa deverá comparar as respostas de cada candidato 
com o gabarito e emitir um vetor denominado resultado, contendo a pontuação correspondente 
a cada aluno. Imprima as notas o resultado de cada aluno.

OBS: Considere que cada questão vale 1 ponto.

*/

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void fillMatrix(char arr[11]) {
    const char possibleAnswers[6] = "abcd";

    for ( int x = 0; x < 10; x++ ) {
        arr[x] = possibleAnswers[rand() % 4];
    }
}

int compareTest(char answers[11], char studentTest[11]) {
    int counter = 0;

    for ( int x = 0; x < 10; x++) {
        if ( answers[x] == studentTest[x] ) counter++;
    }

    return counter;
}

int main() {

    clearScreen();
    srand(time(NULL));

    char answers[11];
    fillMatrix(answers);

    char studentTests[5][11];
    for ( int x = 0; x < 5; x++ ) fillMatrix(studentTests[x]);

    int studentsGrade[5];
    for ( int x = 0; x < 5; x++ ) studentsGrade[x] = compareTest(answers, studentTests[x]);

    printf("\nResults:\n");

    printf("Correct answers:");
    for ( int x = 0; x < 10; x++ ) {
        printf(" %c", toupper(answers[x]));
    }
    printf("\n");

    for (int student = 0; student < 5; student++) {
        printf("\nStudent %i grade: %i\n", student + 1, studentsGrade[student]);
        printf("Answers:");
        for ( int x = 0; x < 10; x++ ) {
            printf(" %c", toupper(studentTests[student][x]));
        }
        printf("\n");
    }

    return 0;
}