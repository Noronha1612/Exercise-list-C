#include "stdio.h"
#include "math.h"

int readLimitedInteger(char* msg, int min, int max) {
    int value;

    while(1) {
        printf("%s", msg);
        scanf("%i", &value);
        getchar();

        if ( (value <= max || max == -1) && value >= min ) break;
        printf("Type a valid value.\n");
    }

    return value;
}

int main() {

    int sumAges = 0, sumRegular = 0, sumGood = 0;

    for(int interviewed = 1; interviewed <= 10; interviewed++) {
        int age, option;
        printf("Interviewed %i, please answer:\n", interviewed);

        age = readLimitedInteger("Your age: ", 0, -1);

        printf("Rate the movie:\n");
        printf("[1] Excellent\n");
        printf("[2] Good\n");
        printf("[3] Regular\n");

        option = readLimitedInteger("Your rate: ", 1, 3);

        printf("\n");

        sumAges = sumAges + age;
        if ( option == 2 ) sumGood++;
        if ( option == 3 ) sumRegular++;
    }

    float agesAverage = (float) sumAges / 10;
    int goodRatingPercentage = sumGood * 10;

    printf("\n\nSurvey result:\n");

    printf("Ages average:");
    fmodf(agesAverage, 1) == 0 ? 
    printf("%i\n", (int) agesAverage) :
    printf("%.1f\n", agesAverage);

    printf("Regular votes: %i\n", sumRegular);

    printf("Percentage good votes: %i%%", goodRatingPercentage);

    return 0;
}