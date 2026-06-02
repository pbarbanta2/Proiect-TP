#include "joc.h"

void curata_ecran() {
    #ifdef _WIN32
        system("cls");
    #else
        printf("\e[1;1H\e[2J");
    #endif
}

void printeaza_celula(char c) {
    if (c=='X') {
        printf(CULOARE_ROSU "X" CULOARE_RESET);
    } else if (c=='0') {
        printf(CULOARE_ALBASTRU "0" CULOARE_RESET);
    } else {
        printf(CULOARE_GALBEN "%c" CULOARE_RESET, c);
    }
}

void afiseaza_tabla(char celule[]) {
    printf("\n ");
    printeaza_celula(celule[0]); printf(" | "); printeaza_celula(celule[1]); printf(" | "); printeaza_celula(celule[2]); printf(" \n");
    printf("---+---+---\n ");
    printeaza_celula(celule[3]); printf(" | "); printeaza_celula(celule[4]); printf(" | "); printeaza_celula(celule[5]); printf(" \n");
    printf("---+---+---\n ");
    printeaza_celula(celule[6]); printf(" | "); printeaza_celula(celule[7]); printf(" | "); printeaza_celula(celule[8]); printf(" \n\n");
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
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // coloane
        {0, 4, 8}, {2, 4, 6}             // diagonale
    };

    for (int i = 0; i < 8; i++) {
        char primul = celule[combinatii[i][0]];
        char al_doilea = celule[combinatii[i][1]];
        char al_treilea = celule[combinatii[i][2]];

        if ((primul == 'X' || primul == '0') && 
            primul == al_doilea && 
            al_doilea == al_treilea) {
            return 1;
        }
    }
    return 0; 
}

int mutare_calculator(char celule[]) {
    int pozitie;
    int mutare_valida = 0;

    while (!mutare_valida) {
       
        pozitie = (rand() % 9) + 1;
        if (celule[pozitie - 1] != 'X' && celule[pozitie - 1] != '0') {
            mutare_valida = 1;
        }
    }

    return pozitie;
}