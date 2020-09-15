#include "stdio.h"
#include "stdlib.h"
#include "time.h"

struct embarcacao {
    int tipo;
    int time;
    int foiDestruido;
};

void inserirBarco(int tabuleiro[11][11], int tipo, int time) {
    while(1) {
        int barcoInserido = 0;

        int id = ((time + 1) * 10) + tipo;

        if ( tipo == 0 ) {
            int px = rand() % 11;
            int py = rand() % 11;

            if ( tabuleiro[px][py] != 0 ) continue;

            tabuleiro[px][py] = id;
            barcoInserido = 1;
        }   

        else if ( tipo == 1 ) {
            int centroX = rand() % 11;
            int centroY = rand() % 11;

            int secundarioX = centroX;
            int secundarioY = centroY == 10? centroY - 1 : centroY + 1;

            if ( tabuleiro[centroX][centroY] == 0 && tabuleiro[secundarioX][secundarioY] == 0 ) {
                tabuleiro[centroX][centroY] = id;
                tabuleiro[secundarioX][secundarioY] = id;
                barcoInserido = 1;
            }
        }

        else if ( tipo == 2 ) {
            int centroX = rand() % 11;
            int centroY = rand() % 11;

            if ( centroX == 0 ) centroX = 1;
            if ( centroY == 10 ) centroY = 9;

            int secundarioX = centroX - 1;
            int secundarioY = centroY + 1;

            if ( tabuleiro[centroX][centroY] == 0 && tabuleiro[secundarioX][secundarioY] == 0 ) {
                tabuleiro[centroX][centroY] = id;
                tabuleiro[secundarioX][secundarioY] = id;
                barcoInserido = 1;
            }
        }

        else if ( tipo == 3 ) {
            int centroX = rand() % 11;
            int centroY = rand() % 11;

            if ( centroX == 0 ) centroX = 1;
            if ( centroY == 0 ) centroY = 1;

            int secundarioX = centroX - 1;
            int secundarioY = centroY - 1;

            if ( tabuleiro[centroX][centroY] == 0 && tabuleiro[secundarioX][secundarioY] == 0 ) {
                tabuleiro[centroX][centroY] = id;
                tabuleiro[secundarioX][secundarioY] = id;
                barcoInserido = 1;
            }
        }

        if ( barcoInserido ) break;
    }
}

void preencherTabuleiro(int tabuleiro[11][11]) {
    for( int time = 0; time < 2; time++ ) {
        for ( int barco = 0; barco < 4; barco++ ) {
            inserirBarco(tabuleiro, barco, time);
        }
    }
}

void mostrarTime(int tabuleiro[11][11], int time) {
    for ( int x = 0; x < 11; x++ ) {
        for ( int y = 0; y < 11; y++ ) {
            int timeLocal = tabuleiro[x][y] / 10;
            int tipoBarco = tabuleiro[x][y] - (time * 10);

            if ( time == timeLocal && tipoBarco == 0 ) printf("S ");
            else if ( time == timeLocal && tipoBarco == 1 ) printf("P ");
            else if ( time == timeLocal && tipoBarco == 2 ) printf("C ");
            else if ( time == timeLocal && tipoBarco == 3 ) printf("N ");
            else printf(". ");
        }

        printf("\n");
    }
}

int main() {

    srand(time(NULL));

    int tabuleiro[11][11];
    for ( int x = 0; x < 11; x++ ) {
        for ( int y = 0; y < 11; y++ ) {
            tabuleiro[x][y] = 0;
        }
    }

    preencherTabuleiro(tabuleiro);

    for ( int x = 0; x < 11; x++ ) {
        for ( int y = 0; y < 11; y++ ) {
            printf("%i ", tabuleiro[x][y]);
        }

        printf("\n");
    }

    mostrarTime(tabuleiro, 1);

    printf("\n\n");
    mostrarTime(tabuleiro, 2);

    return 0;
}