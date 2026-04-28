#include "joc.h"

void curata_ecran() {
    #ifdef _WIN32
        system("cls");
    #else
        printf("\e[1;1H\e[2J");
    #endif
}

void afiseaza_tabla(char celule[]) {
    printf("\n");
    printf(" %c | %c | %c \n", celule[0], celule[1], celule[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", celule[3], celule[4], celule[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", celule[6], celule[7], celule[8]);
    printf("\n");
}

int marcheaza_casuta(char celule[], int pozitie, char simbol) {
    // pozitie valida
    if (pozitie >= 1 && pozitie <= 9 && celule[pozitie - 1] != 'X' && celule[pozitie - 1] != '0')
    {
        celule[pozitie - 1] = simbol;
        return 1; // Succes
    }
    return 0; 
}

int verifica_castig(char celule[]) {
    //combinatii de castig
    int combinatii[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // lnii
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // cloane
        {0, 4, 8}, {2, 4, 6}             // dagonale
    };

    for (int i = 0; i < 8; i++) {
        if (celule[combinatii[i][0]] == celule[combinatii[i][1]] &&
            celule[combinatii[i][1]] == celule[combinatii[i][2]]) {
            return 1; // castig
        }
    }
    return 0;
}