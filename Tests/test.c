#include "stdio.h"

int main() {

    if ( 1 == 1 && 1 != 1 || 1 == 1 && 1 != 1 || 1 == 1 && 1 != 1 ) {
        printf("true\n");
    }
    else {
        printf("false\n");
    }

    return 0;
}