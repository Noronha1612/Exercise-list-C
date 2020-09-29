#include "stdio.h"
#include "string.h"

int main() {

    int age;

    while(1) {
        printf("Type your age:");
        scanf("%i", &age);

        if ( age >= 0 ) break;
        printf("Type a valid age!\n");
    }

    printf("\nWhat movie do you want to watch?\n");
    printf("[1] Titanic (16)\n");
    printf("[2] Woody Woodpecker\n");
    printf("[3] Friday the 13th: Return of Jason (18)\n");
    printf("[4] None\n");

    int option;

    while(1) {
        printf("Select an option:");
        scanf("%i", &option);

        if ( option <= 4 && option >= 1 ) break;
        printf("Please, select a valid option.");
    }

    int canWatchBool;
    char movie[40];

    char movies[3][40] = {
        "Titanic",
        "Woody Woodpecker",
        "Friday the 13th: Return of Jason"
    };

    int agesAllowByMovies[3] = {
        16,
        0,
        18
    };

    if ( option != 4 ) {
        if ( age >= agesAllowByMovies[option - 1] ) canWatchBool = 1;
        else canWatchBool = 0;

        strcpy(movie, movies[option - 1]);

        if ( canWatchBool )
            printf("\nYou bought successfully a ticket to watch %s!\n", movie);
        else
            printf("\nUnfortunately, you are too young to watch this movie.\n");
    
    }
    else {
        printf("\nThanks for comming! So long.\n");
    }

    return 0;
}