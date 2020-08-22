#include "stdio.h"
#include "ctype.h"

int main() {
        char wantToBuyMore;

        while(1) {
            printf("Do you want to buy something else? [Y/N]");
            wantToBuyMore = tolower(getchar());
            getchar();

            if ( wantToBuyMore == 'y' || wantToBuyMore == 'n' ) break;
            printf("Select a valid option!\n");
        }

        printf("\nOutside\n");
    return 0;
}