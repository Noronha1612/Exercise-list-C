#include "stdio.h"

int main() {

    int age;

    while(1) {
        printf("Type your age:");
        scanf("%i", &age);

        if ( age >= 0 ) break;
        printf("Type a valid age!\n");
    }

    float value;

    if ( age <= 10 ) value = 30;
    else if ( age <= 29 ) value = 60;
    else if ( age <= 45 ) value = 120;
    else if ( age <= 59 ) value = 150;
    else if ( age <= 65 ) value = 250;
    else value = 400;

    printf("You must pay USD %.2f for the service", value);

    return 0;
}