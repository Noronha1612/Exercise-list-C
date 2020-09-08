#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"

/*

O código de César é uma das mais simples e conhecidas técnicas de criptografia. 
É um tipo de substituição na qual cada letra do texto é substituída por outra, 
que se apresenta no alfabeto abaixo dela um número fixo de vezes. Por exemplo, 
com uma troca de três posições, ‘A’ seria substituído por ‘D’, ‘B’ se tornaria ‘E’, e assim por diante. 
Implemente um programa que faça uso desse Código de César (3 posições), 
entre com uma string e retorne a string codificada. 
Exemplo: String: a ligeira raposa marrom saltou sobre o cachorro cansado, 
Nova string: D OLJHLUD UDSRVD PDUURP VDOWRX VREUH R FDFKRUUR FDQVDGR (com caracteres maiúsculos)

*/

int main() {
    const char letters[26] = "abcdefghijklmnopqrstuvwxyz";

    char text[150];

    printf("Type something: ");
    fgets(text, 150, stdin);

    char encriptedText[150];

    for ( int x = 0; x < strlen(text); x++ ) {
        int charIndex = -1;

        for ( int y = 0; y < 26; y++ ) {
            if ( text[x] == letters[y] ) {
                charIndex = y < 23 ? y + 3 : y - 23; 
            }
        }

        if ( charIndex != -1 ) encriptedText[x] = toupper(letters[charIndex]);
        else encriptedText[x] = text[x];
    }

    printf("\nEncrypted text = %s\n", encriptedText);

    return 0;
}