#include "stdio.h"
#include "math.h"

int main() {

    float num;

    while(1) {
        printf("Type the value between 20 and 100:");
        scanf("%f", &num);

        if ( num <= 100 && num >= 20 ) break;

        if ( num > 100 ) printf("The number is higher than 100\n\n");
        else printf("The number is lower than 20\n\n");
    }

    if ( fmod(num, 3) == (double)0 && fmod(num, 5) == (double)0 ) {
        if ( fmod(num, 1) == 0 ) printf("The number %.0f can be divided by 3 and 5\n", num);
        else printf("The number %f can be divided by 3 and 5\n", num);
        
    }
    else {
        printf("The number cannot be divided by 3 and 5\n");
    }

    return 0;
}