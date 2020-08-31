#include <stdio.h>
#include "conio.h"
#include "stdlib.h"

void up(int** arr, int playerY, int playerX) {
  if ( playerY > 0 ) {
    arr[playerX][playerY] = 0;
    arr[playerX - 1][playerY] = 1;
  }
}

void down(int** arr, int playerY, int playerX) {
  if ( playerY < 4 ) {
    arr[playerX][playerY] = 0;
    arr[playerX + 1][playerY] = 1;
  }
}

void left(int** arr, int playerY, int playerX) {
  if ( playerX > 0 ) {
    arr[playerX][playerY] = 0;
    arr[playerX][playerY - 1] = 1;
  }

}

void right(int** arr, int playerY, int playerX) {
  if ( playerX < 4 ) {
    arr[playerX][playerY] = 0;
    arr[playerX][playerY + 1] = 1;
  }
}

int main()
{
  int matrix[5][5];

  for (int line = 0; line < 5; line++) {
    for ( int column = 0; column < 5; column++ ) {
      matrix[line][column] = 0;
    }
  }

  matrix[0][0] = 1;

  char keyPressed;
  
  int posX = 0, posY = 0;

  while(1) {
    if ( !kbhit() ) {
      for ( int line = 0; line < 5; line++ ) {
        for ( int column = 0; column < 5; column++ ) {
          printf("[%i] ", matrix[line][column]);
        }
        printf("\n");
      }

      keyPressed = getch();

      if ( keyPressed == 'w' ) {
        up(matrix, posY, posX);
        posX++;
        printf("\napertou W\n");
      }
      else if ( keyPressed == 'a' ) {
        left(matrix, posY, posX);
        posX++;
        printf("\napertou A\n");
      }
      else if ( keyPressed == 's' ) {
        down(matrix, posY, posX);
        posX--;
        printf("\napertou S\n");
      }
      else if ( keyPressed == 'd' ) {
        right(matrix, posY, posX);
        posX--;
        printf("\napertou D\n");
      }
    }
  }

  return 0; 
}
