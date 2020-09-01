#include "stdio.h"
#include "math.h"

/*

Leia um vetor com 10 números reais, 
ordene os elementos deste vetor de forma crescente (menor para o maior), 
e no final imprima os elementos do vetor ordenado.

*/

void readElements(float* arr, int size) {
    for ( int x = 0; x < size; x++ ) {
        float element;

        printf("Type the %i element: ", x + 1);
        scanf("%f", &element);
        getchar();

        arr[x] = element;
    }
}

int main() {
    float array[10];

    printf("Array elements:\n");
    readElements(array, 10);

    float sortedArray[10];
    int counterSortedArray = 0;

    for ( int x = 0; x < 10; x++ ) {
        float element = array[x];
        int hasIncluded = 0;
        
        float nextElement;
        float beingReplaced;
        for ( int i = 0; i < counterSortedArray; i++ ) {
            if ( element < sortedArray[i] && hasIncluded == 0 ) { // Para trocar a ordem, só trocar o "<" por ">"
                nextElement = sortedArray[i];
                beingReplaced = sortedArray[i + 1];
                sortedArray[i + 1] = nextElement;

                sortedArray[i] = element;
                hasIncluded = 1;
            } 
            else if ( hasIncluded ) {
                nextElement = beingReplaced;
                beingReplaced = sortedArray[i + 1];
                sortedArray[i + 1] = nextElement;
            }
        }

        if ( hasIncluded ) {
            counterSortedArray++;
            continue;
        }

        if ( x == counterSortedArray ) {
            sortedArray[x] = element;
            counterSortedArray++;
        }
    }

    printf("\nSorted array elements: ");

    for ( int x = 0; x < 10; x++ ) {
        fmodf(sortedArray[x], 1) == 0 ?
        printf("%i ",(int) sortedArray[x]) :
        printf("%f", sortedArray[x]);
    }
    
    printf("\n");

    return 0;
}
