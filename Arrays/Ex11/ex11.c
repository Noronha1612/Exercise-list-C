#include "stdio.h"

/*

Faça um programa que leia dois vetores de 10 elementos. 
Crie um vetor que seja a união entre os 2 vetores anteriores, ou seja, 
que contém os números dos dois vetores sem repetição.

*/

void readElements(int arr[], int size) {
    for ( int x = 0; x < size; x++ ) {
        int element;

        printf("Type the %i element: ", x + 1);
        scanf("%i", &element);
        getchar();

        arr[x] = element;
    }
}

int insertIfNotExist(int arr[], int size, int element, int index, int has0) {
    int doesElementExistOnArray = 0;

    if ( element == 0 && !has0 ) {
        arr[index] = element;
        return 2;
    }

    for ( int x = 0; x < size; x++ ) {
        if ( arr[x] == element ) doesElementExistOnArray = 1;
    }


    if ( !doesElementExistOnArray ) {
        arr[index] = element;
        return 1;
    }

    return 0;
}

int main() {
  
  int arr1[10], arr2[10];

  printf("Array 1 elements:\n");
  readElements(arr1, 10);

  printf("\nArray 2 elements:\n");
  readElements(arr2, 10);

  int commonElements[10];
  int counterCommonElements = 0;
  int commonElementsDoesHave0 = 0;

  for ( int x = 0; x < 10; x++ ) {
      int e1 = arr1[x];
      int doesE1ExistOn2 = 0;

      for ( int y = 0; y < 10; y++ ) {
          if ( e1 == arr2[y] ) doesE1ExistOn2 = 1;
      }

      if ( doesE1ExistOn2 ) {
          int didInsert = insertIfNotExist(commonElements, 10, e1, counterCommonElements, commonElementsDoesHave0);

          if ( didInsert ) {
              counterCommonElements++;
              if ( didInsert == 2 ) {
                  commonElementsDoesHave0 = 1;
              }
          }
      }
  }

  printf("\nCommon elements:");

  for ( int x = 0; x < counterCommonElements; x++ ) {
      printf(" %i", commonElements[x]);
  }

  printf("\n");

  return 0;
}
