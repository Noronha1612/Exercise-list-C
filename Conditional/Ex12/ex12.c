#include "stdio.h"

float readLength(char* msg) {
    float length;

    while(1) {
        printf("%s", msg);
        scanf("%f", &length);

        if ( length > 0 ) break;
        printf("Type a valid length\n");
    }

    return length;
}

int main() {

    float A, B, C;

    A = readLength("Type the length of A:");
    B = readLength("Type the length of B:");
    C = readLength("Type the length of C:");

    if ( A + B < C || A + C < B || B + C < A ) {
        printf("Those lengths cannot build a triangle\n");
    }
    else {
        if ( A == B && B == C && A == C ) {
            printf("Those lengths can build an equilateral triangle\n");
        }
        else if ( A == B && A != C || A == C && A != B || B == C && B != A ) {
            printf("Those lengths can build an isosceles triangle\n");
        }
        else {
            printf("Those lengths can build an scalene triangle\n");
        }
    }

    return 0;
}