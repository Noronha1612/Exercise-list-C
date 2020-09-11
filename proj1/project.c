#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "time.h"

/*

Entity codes:

1: Player
2: Cersei
3: NightKing
4: Enemy
5: Obstacle
6: Potion

*/

struct entity {
    int id;
    char charIdentifier;
    int health;
};

struct player {
    int id;
    char charIdentifier;
    int health;
    int hasMatchCersei;
    int location[2];
};

void generateRandomEntities(int mainBoard[10][10]) {
    srand(time(NULL));

    for ( int enemy = 0; enemy < 20; enemy++ ) {
        while(1) {
            int x = rand() % 10;
            int y = rand() % 10;

            if ( mainBoard[x][y] == 0 ) {
                mainBoard[x][y] = 4;

                break;
            }
        }
    }

    for ( int potion = 0; potion < 10; potion++ ) {
        while(1) {
            int x = rand() % 10;
            int y = rand() % 10;

            if ( mainBoard[x][y] == 0 ) {
                mainBoard[x][y] = 5;

                break;
            }
        }
    }

    for ( int obstacle = 0; obstacle < 10; obstacle++ ) {
        while(1) {
            int x = rand() % 10;
            int y = rand() % 10;

            if ( mainBoard[x][y] == 0 ) {
                mainBoard[x][y] = 6;

                break;
            }
        }
    }
}

void showBoard( int mainBoard[10][10], char johnId, char cerseiId, char nightKingId ) {
    for ( int x = 0; x < 10; x++ ) {
        for ( int y = 0; y < 10; y++ ) {
            int identifier = mainBoard[x][y];

            if ( identifier == 1 ) printf("%c ", johnId);
            else if ( identifier == 2 ) printf("%c ", cerseiId);
            else if ( identifier == 3 ) printf("%c ", nightKingId);
            else printf(". ");
        }
        printf("\n");
    }
    
    printf("\nYou can walk using [W/A/S/D]\n");
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Will return a code { 100: can move, 101: obstacle, 102: enemy, 103: potion, 104: out of range, 105: cersei, 106: nightKing }
int movePlayer( int mainBoard[10][10], int johnPosition[2], char move ) {
    int johnX = johnPosition[0];
    int johnY = johnPosition[1];

    if ( move == 'w' ) {
        if ( johnX == 0 ) return 104;

        int nextSquare = mainBoard[johnX - 1][johnY];

        if ( nextSquare == 5 ) return 101;

        if ( nextSquare == 2 ) return 105;

        if ( nextSquare == 3 ) return 106;

        if ( nextSquare == 4 ) {
            mainBoard[johnX][johnY] = 0;
            mainBoard[johnX - 1][johnY] = 1;
            johnPosition[0] = johnX - 1;
            johnPosition[1] = johnY;
            return 102;
        }

        if ( nextSquare == 6 ) {
            mainBoard[johnX][johnY] = 0;
            mainBoard[johnX - 1][johnY] = 1;
            johnPosition[0] = johnX - 1;
            johnPosition[1] = johnY;
            return 103;
        }

        if ( nextSquare == 0 ) {
            mainBoard[johnX][johnY] = 0;
            mainBoard[johnX - 1][johnY] = 1;
            johnPosition[0] = johnX - 1;
            johnPosition[1] = johnY;
            return 100;
        }
    }

    if ( move == 's' ) {
        if ( johnX == 9 ) return 104;

        int nextSquare = mainBoard[johnX + 1][johnY];

        if ( nextSquare == 5 ) return 101;

        if ( nextSquare == 2 ) return 105;

        if ( nextSquare == 3 ) return 106;

        if ( nextSquare == 4 ) {
            mainBoard[johnX][johnY] = 0;
            mainBoard[johnX + 1][johnY] = 1;
            johnPosition[0] = johnX + 1;
            johnPosition[1] = johnY;
            return 102;
        }

        if ( nextSquare == 6 ) {
            mainBoard[johnX][johnY] = 0;
            mainBoard[johnX + 1][johnY] = 1;
            johnPosition[0] = johnX + 1;
            johnPosition[1] = johnY;
            return 103;
        }

        if ( nextSquare == 0 ) {
            mainBoard[johnX][johnY] = 0;
            mainBoard[johnX + 1][johnY] = 1;
            johnPosition[0] = johnX + 1;
            johnPosition[1] = johnY;
            return 100;
        }
    }

    if ( move == 'a' ) {
        if ( johnY == 0 ) return 104;

        int nextSquare = mainBoard[johnX][johnY - 1];

        if ( nextSquare == 5 ) return 101;

        if ( nextSquare == 2 ) return 105;

        if ( nextSquare == 3 ) return 106;

        if ( nextSquare == 4 ) {
            mainBoard[johnX][johnY] = 0;
            mainBoard[johnX][johnY - 1] = 1;
            johnPosition[0] = johnX;
            johnPosition[1] = johnY - 1;
            return 102;
        }

        if ( nextSquare == 6 ) {
            mainBoard[johnX][johnY] = 0;
            mainBoard[johnX][johnY - 1] = 1;
            johnPosition[0] = johnX;
            johnPosition[1] = johnY - 1;
            return 103;
        }

        if ( nextSquare == 0 ) {
            mainBoard[johnX][johnY] = 0;
            mainBoard[johnX][johnY - 1] = 1;
            johnPosition[0] = johnX;
            johnPosition[1] = johnY - 1;
            return 100;
        }
    }

    if ( move == 'd' ) {
        if ( johnY == 9 ) return 104;

        int nextSquare = mainBoard[johnX][johnY + 1];

        if ( nextSquare == 5 ) return 101;

        if ( nextSquare == 2 ) return 105;

        if ( nextSquare == 3 ) return 106;

        if ( nextSquare == 4 ) {
            mainBoard[johnX][johnY] = 0;
            mainBoard[johnX][johnY + 1] = 1;
            johnPosition[0] = johnX;
            johnPosition[1] = johnY + 1;
            return 102;
        }

        if ( nextSquare == 6 ) {
            mainBoard[johnX][johnY] = 0;
            mainBoard[johnX][johnY + 1] = 1;
            johnPosition[0] = johnX;
            johnPosition[1] = johnY + 1;
            return 103;
        }

        if ( nextSquare == 0 ) {
            mainBoard[johnX][johnY] = 0;
            mainBoard[johnX][johnY + 1] = 1;
            johnPosition[0] = johnX;
            johnPosition[1] = johnY + 1;
            return 100;
        }
    }
}

// Will return -1 if player lose, 0 if cercei joins john, 2 if player kills cersei
int matchCersei(int playerHealth, int cerseiHealth) {

    printf("\nJohn found Cersei, and try to convince her to join and figth by his side.\n");
    printf("(You will have 5 chances to reach at least 60%% of power attack 3 times)\n");

    // Negotiation
    int didCerseiJoin = 0;
    int timesReached = 0;

    srand(time(NULL));
    
    for ( int x = 0; x < 5; x++ ) {
        printf("\nArguments: %i\n", timesReached);

        printf("Type ENTER to give %ith shoot.\n", x + 1);
        getchar();

        int powAttack = rand() % 100;

        printf("You reached %i%%\n\n", powAttack);

        if ( powAttack >= 60 ) {
            timesReached++;

            if ( timesReached == 3 ) {
                didCerseiJoin = 1;
                break;
            }
        }
    }

    if ( didCerseiJoin ) return 0;

    clearScreen();

    // War
    printf("\n\nCersei did not join john and started a war.\n");
    printf("(John starts attacking, if you reach at least 50%% of power attack, you will inflict 10HP damage to Cersei.\n");
    printf("Otherwise, the same thing she will do to you.)\n\n");

    int player = 1;
    int didPlayerWin = 0;

    srand(time(NULL));

    while(1) {
        printf("Round: %s\n", player == 1 ? "John" : "Cersei");
        printf("Your health: %iHP\n", playerHealth);
        printf("Cersei health: %iHP\n", cerseiHealth);

        if ( player == 1 ) {
            printf("Type ENTER to attack Cersei");
            getchar();

            clearScreen();

            int powAttack = rand() % 100;

            if ( powAttack >= 50 ) {
                cerseiHealth -= 10;
                printf("You inflicted 10HP damage to cersei\n\n");
            }
            else {
                printf("You missed\n\n");
            }

            if ( cerseiHealth <= 0 ) {
                didPlayerWin = 1;
                break;
            }
        }
        else {
            printf("Type ENTER to continue");
            getchar();

            clearScreen();

            int powAttack = rand() % 100;

            if ( powAttack >= 50 ) {
                playerHealth -= 10;
                printf("Cersei inflicted 10HP damage to you.\n\n");
            }
            else {
                printf("Cersei missed\n\n");
            }

            if ( playerHealth <= 0 ) break;
        }

        player = player == 1 ? 0 : 1;
    }

    clearScreen();

    if ( didPlayerWin ) return playerHealth;
    
    return -1;
    
}

int main() {

    int mainBoard[10][10];

    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            mainBoard[x][y] = 0;
        }
    }

    struct player john;
    john.id = 1;
    john.health = 100;
    john.charIdentifier = 'J';
    john.hasMatchCersei = 0;
    john.location[0] = 0;
    john.location[1] = 0;
    mainBoard[0][0] = john.id;

    struct entity cersei;
    cersei.id = 2;
    cersei.health = 100;
    cersei.charIdentifier = 'C';
    mainBoard[4][4] = cersei.id;

    struct entity nightKing;
    nightKing.id = 3;
    nightKing.health = 200;
    nightKing.charIdentifier = 'N';
    mainBoard[9][9] = nightKing.id;

    generateRandomEntities(mainBoard);

    char move;
    int code = 0;
    
    clearScreen();

    int didUserWin = 0;

    while(1) {
        printf("Your health: %iHP\n", john.health);
        printf("Objective: ");
        john.hasMatchCersei ? printf("Go fight Night King!\n") : printf("Go find Cersei!\n"); 
        showBoard(mainBoard, john.charIdentifier, cersei.charIdentifier, nightKing.charIdentifier);

        while(1) {
            move = getch();

            if ( move == 'w' || move == 'a' || move == 's' || move == 'd' ) break;
        }

        clearScreen();

        code = movePlayer(mainBoard, john.location, move);
        if ( code != 0 ) {
            if ( code == 100 ) printf("You moved!");
            else if ( code == 101 ) printf("You cannot move to there, there is an obstacle there.");

            else if ( code == 102 ) {
                john.health -= 1;

                printf("You found an enemy! You killed him but you lost 1HP");
            }

            else if ( code == 103 ) {
                john.health += 5;

                printf("You found a potion! You gained 5HP");
            }

            else if ( code == 104 ) printf("Out of range!");

            else if ( code == 105 ) {
                int result = matchCersei(john.health, cersei.health);

                if ( result == -1 ) break;

                if ( result == 0 ) {
                    printf("Cersei joined John (Health increased 100HP)");
                    john.health += 100;
                }
                else {
                    printf("John won the war!");
                    john.health = result;
                }
                mainBoard[4][4] = 0;
                john.hasMatchCersei = 1;
            }

            else if ( code == 106 ) {
                if ( !john.hasMatchCersei ) printf("You must match Cersei first.");
                else printf("Final fight!");
            }

            printf("\n\n");
        }
    }

    if ( didUserWin ) printf("\n\nYOU WON!\n\n");
    else printf("\n\nYou died...\n\n");

    return 0;
}