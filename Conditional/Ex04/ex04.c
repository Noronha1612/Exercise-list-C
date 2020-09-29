#include "stdio.h"
#include "ctype.h"

int main() {

    char sex;

    while(1) {
        printf("Type the sex: (M to Male and F to Female)");
        sex = tolower(getchar());
        getchar();

        if ( sex == 'm' || sex == 'f' ) break;

        printf("Type a valid letter\n");
    }

    int age;

    while(1) {
        printf("Type the age:");
        scanf("%i", &age);

        if ( age >= 0 ) break;

        printf("Type a valid age\n");
    }

    if ( sex == 'f' && age < 25 ) {
        printf("ACCEPTED\n");
    }
    else {
        printf("NOT ACCEPTED\n");
    }

    return 0;
}