#include "stdio.h"
#include "math.h"
#include "string.h"

/*

Faça um programa que simule a urna eletrônica. A tela a ser apresentada deverá ser da seguinte forma:
As opções são:
1. Candidato Jair Rodrigues
2. Candidato Carlos Luz
3. Candidato Neves Rocha
4. Nulo
5. Branco
Entre com o seu voto:
O programa deverá ler os votos dos eleitores e, quando o número 6 for lido, apresentar as seguintes informações: 
a) O número de votos de cada candidato; 
b) A porcentagem de votos nulos; 
c) A porcentagem de votos brancos; 
d) O candidato vencedor.

*/

int main() {

    char candidates[3][255] = {
        "Jair Rodrigues",
        "Carlos Luz",
        "Neves Rocha"
    };

    int codeAndVotes[3][2] = {
        { 1, 0 },
        { 2, 0 },
        { 3, 0 }
    };

    int nullVotes = 0, emptyVotes = 0, votes = 0;

    printf("Select your option:\n");
    for ( int cand = 0; cand <= 2; cand++ ) {
        printf("[%i] %s\n", codeAndVotes[cand][0], candidates[cand]);
    }
    printf("[4] Null\n");
    printf("[5] Empty\n");
    printf("[6] End election\n");

    while(1) {
        int option;

        while(1) {
            printf("Option: ");
            scanf("%i", &option);
            getchar();

            if ( option <= 6 && option >= 1 ) break;
            printf("Type a valid option!\n");
        }

        if ( option == 6 ) break;

        votes++;

        if ( option == 1 ) codeAndVotes[0][1] = codeAndVotes[0][1] + 1;
        else if ( option == 2 ) codeAndVotes[1][1] = codeAndVotes[1][1] + 1;
        else if ( option == 3 ) codeAndVotes[2][1] = codeAndVotes[2][1] + 1;
        else if ( option == 4 ) nullVotes++;
        else if ( option == 5 ) emptyVotes++;

        printf("Your vote has been computed.\n\n");
    }

    float nullVotesPercentage = ((float) nullVotes / (float) votes) * 100;
    float emptyVotesPercentage = ((float) emptyVotes / (float) votes) * 100;

    int winnerVotes = 0, winnerCode = 0;
    int didDrawOccurred = 0;
    int drawTiedCodes[2] = { 0, 0 };
    int allHaveTied = 1;

    printf("\nResult:\n");

    for ( int cand = 0; cand <= 2; cand++ ) {
        printf("[%i] %s - %i votes\n", codeAndVotes[cand][0], candidates[cand], codeAndVotes[cand][1]);

        int candCode = codeAndVotes[cand][0];
        int candVotes = codeAndVotes[cand][1];

        if ( winnerVotes != candVotes && cand != 0 ) allHaveTied = 0;

        if ( candVotes > winnerVotes ) {
            winnerVotes = candVotes;
            winnerCode = candCode;
        }
    }

    if ( codeAndVotes[0][1] == codeAndVotes[1][1] && codeAndVotes[0][1] != codeAndVotes[2][1] ) {
        didDrawOccurred = 1;
        drawTiedCodes[0] = 1;
        drawTiedCodes[1] = 2;
    }
    else if ( codeAndVotes[1][1] == codeAndVotes[2][1] && codeAndVotes[1][1] != codeAndVotes[0][1] ) {
        didDrawOccurred = 1;
        drawTiedCodes[0] = 2;
        drawTiedCodes[1] = 3;
    }
    else if ( codeAndVotes[0][1] == codeAndVotes[2][1] && codeAndVotes[0][1] != codeAndVotes[1][1] ) {
        didDrawOccurred = 1;
        drawTiedCodes[0] = 1;
        drawTiedCodes[1] = 3;
    }

    printf("\nPercentage null votes: ");
    if ( winnerCode == 0 ) printf("0%%\n");
    else {
        fmodf(nullVotesPercentage, 1) == 0 ? 
        printf("%i%%\n", (int) nullVotesPercentage) : 
        printf("%.2f%%\n", nullVotesPercentage);
    }
    
    printf("\nPercentage empty votes: ");
    
    if ( winnerCode == 0 ) printf("0%%\n");
    else {
        fmodf(emptyVotesPercentage, 1) == 0 ? 
        printf("%i%%\n", (int) emptyVotesPercentage) : 
        printf("%.2f%%\n", emptyVotesPercentage);
    }

    if ( allHaveTied || winnerVotes == 0 ) printf("\nEveryone tied!\n");
    else if ( didDrawOccurred ) {
        printf("\n%s and %s has tied!\n", candidates[drawTiedCodes[0] - 1], candidates[drawTiedCodes[1] - 1]);
    }
    else {
        printf("\n%s has won!\n", candidates[winnerCode - 1]);
    }

    return 0;
}