#include "stdio.h"
#include "stdlib.h"

/*

Criar um algoritmo que leia dois vetores de números inteiros, 
tendo cada um 10 e 20 elementos respectivamente, 
e apresentar os elementos que não são comuns aos dois vetores.

*/

void readElements(int* array, int size) {
    for ( int x = 0; x < size; x++ ) {
        int element;

        printf("Type the %i element: ", x + 1);
        scanf("%i", &element);
        getchar();

        array[x] = element;
    }
}

int insertIfNotExist(int* array, int size, int index, int element) {
    int doesElementAlreadyExist = 0;

    for ( int e = 0; e < size; e++ ) {
        if ( element == array[e] ) doesElementAlreadyExist = 1;
    }

    if ( !doesElementAlreadyExist ) {
        array[index] = element;
        return 1;
    }

    return 0;
}

int main() {

    int array1[10], array2[20];

    printf("Array 1 elements:\n");
    readElements(array1, 10);

    printf("\nArray 2 elements:\n");
    readElements(array2, 20);

    int in1NotIn2[10], in2NotIn1[20];
    int counter1 = 0, counter2 = 0;

    for ( int x = 0; x < 10; x++ ) {
        int e1 = array1[x];
        int does1ExistOn2 = 0;

        for ( int y = 0; y < 20; y++ ) {
            if ( e1 == array2[y] ) does1ExistOn2 = 1;
        }

        if ( !does1ExistOn2 ) {
            int didInsert = insertIfNotExist(in1NotIn2, 10, counter1, e1);
            if ( didInsert ) counter1++;
        }
    }

    for ( int x = 0; x < 20; x++ ) {
        int e2 = array2[x];
        int does2ExistOn1 = 0;

        for ( int y = 0; y < 10; y++ ) {
            if ( e2 == array1[y] ) does2ExistOn1 = 1;
        }

        if ( !does2ExistOn1 ) {
            int didInsert = insertIfNotExist(in2NotIn1, 20, counter2, e2);
            if ( didInsert ) counter2++;
        }
    }

    printf("\nDistinct elements:\n");

    printf("Array1 not in Array2:");
    for ( int x = 0; x < counter1; x++ ) {
        printf(" %i", in1NotIn2[x]);
    }
    printf("\n");

    printf("Array2 not in Array1:");
    for ( int x = 0; x < counter2; x++ ) {
        printf(" %i", in2NotIn1[x]);
    }
    printf("\n");

    return 0;
}