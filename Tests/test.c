#include <stdio.h>

int main() {

  int array[20];

  if ( array[3] == 0 ) printf("%i", !!array[3]);
  else printf("false");

  return 0;
}
