#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*

Escreva um programa que leia a idade e o primeiro nome de várias pessoas. 
Seu programa deve terminar quando uma idade negativa for digitada. 
Ao terminar, seu programa deve escrever o nome e a idade da pessoa mais jovem e mais velha.

*/

int main() {
    int counter = 0;

    int oldestAge = -1, youngestAge = -1;
    char oldestName[50], youngestName[50];

    while(1) {
        int pAge;
        char pName[50];

        printf("Person %i, your age: (Negative to stop) ", counter + 1);
        scanf("%i", &pAge);
        getchar();

        if ( pAge < 0 ) break;

        printf("Now, your first name: ");
        fgets(pName, 50, stdin);

        if ( oldestAge == -1 || pAge > oldestAge ) {
            strcpy(oldestName, pName);
            oldestAge = pAge;
        }

        if ( youngestAge == -1 || pAge < youngestAge ) {
            strcpy(youngestName, pName);
            youngestAge = pAge;
        }

        counter++;
    }

    if ( counter == 0 ) printf("\nNot a single person has been signed.\n");
    else {
        printf("\nOldest person: %s [%i]\n", oldestName, oldestAge);
        printf("Youngest person: %s [%i]\n", youngestName, youngestAge);
    }

    return 0;
}