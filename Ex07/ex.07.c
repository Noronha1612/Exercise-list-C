#include "stdio.h"
#include "math.h"

float getValue(char* msg) {
    float value;

    printf("%s", msg);
    scanf("%f", &value);

    return value;
}

int main() {

    float radius, cx, cy, px, py;

    radius = getValue("Type the circle radius:");
    cx = getValue("Type the X of the circle center:");
    cy = getValue("Type the Y of the circle center:");
    py = getValue("Type the X of the point:");
    py = getValue("Type the Y of the point:");

    float pointVector[1] = { px - cx, py - cy };

    float lengthPointToCenter = sqrtf(powf(pointVector[0], 2) + powf(pointVector[1], 2));

    if ( lengthPointToCenter < radius ) {
        printf("\nINSIDE!");
    }
    else {
        printf("\nOUTSIDE");
    }

    return 0;
}