#include <stdio.h>
#include "stdlib.h"

int main() {
  
  int *arr;
  int counterArr = 0;

  arr = malloc(sizeof(int));

  arr[counterArr++] = 2;
  
  for ( int x = 0; x < counterArr; x++ ) {
    printf("%i ", arr[x]);
  }

  printf("\n");

  arr[counterArr++] = 7;
  
  for ( int x = 0; x < counterArr; x++ ) {
    printf("%i ", arr[x]);
  }

  printf("\n");

  arr[counterArr++] = 12;
  
  for ( int x = 0; x < counterArr; x++ ) {
    printf("%i ", arr[x]);
  }

  return 0;
}
