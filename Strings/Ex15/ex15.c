#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*

Implemente um programa que leia duas strings, str1 e str2, e um valor inteiro positivo N. 
Concatene a str2 N vezes com str1.

*/

void readString(char* msg, char* str) {
    printf("%s", msg);
    fgets(str, 150, stdin);
}

int main() {

    char str1[150], str2[150];

    int times;

    readString("Type something to string 1: ", str1);
    readString("Type something to string 2: ", str2);

    while(1) {
        printf("How many times would you like to concat \"%s\" with \"%s\"? ", str2, str1);
        scanf("%i", &times);
        getchar();

        if ( times >= 0 ) break;
        printf("Type a valid quantity.\n");
    }

    int concatedStringLength = strlen(str1) + (strlen(str2) * times);

    char concatedString[concatedStringLength];
    strcat(concatedString, str1);

    for ( int x = 0; x < times; x++ ) {
        strcat(concatedString, str2);
    }

    printf("\nConcated string: %s\n", concatedString);

    return 0;
}