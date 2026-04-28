#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "joc.h"

int main() {
    // initializam tabla cu cifrele 1-9 pentru a ghida jucatorul
    char tabla[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char jucator1, jucator2;

    printf("==============================\n");
    printf("   BINE AI VENIT LA X SI 0    \n");
    printf("==============================\n\n");

    // alegerea simbolului
    do {
        printf("Jucator 1, alege simbolul (X sau 0): ");
        scanf(" %c", &jucator1);
        jucator1 = toupper(jucator1); // Convertim în majusculă
    } while (jucator1 != 'X' && jucator1 != '0');

    // atribuim automat simbolul pentru Jucătorul 2
    jucator2 = (jucator1 == 'X') ? '0' : 'X';

    printf("\nConfiguratie stabilita:\n");
    printf("Jucator 1: %c\n", jucator1);
    printf("Jucator 2: %c\n", jucator2);
    printf("------------------------------\n");
    printf("Instructiuni: Introdu cifra corespunzatoare pozitiei.\n");

    afiseaza_tabla(tabla);
    int runda, pozitie;
    char simbol_curent;

    for (runda = 0; runda < 9; runda++) 
    {
        // Stabilim cine mută: Jucătorul 1 în rundele pare, Jucătorul 2 în cele impare
        simbol_curent = (runda % 2 == 0) ? jucator1 : jucator2;
        
        int succes = 0;
        while (!succes) {
            printf("Randul simbolului %c. Alege pozitia: ", simbol_curent);
            if (scanf("%d", &pozitie) != 1) {
                while(getchar() != '\n'); // curatam buffer-ul în caz de input greșit (litere)
                continue;
            }

            succes = marcheaza_casuta(tabla, pozitie, simbol_curent);
            
            if (!succes) {
                printf("Pozitie invalida sau ocupata! Incearca din nou.\n");
            }
        }

        curata_ecran();
        printf("Ultima mutare: %c la pozitia %d\n", simbol_curent, pozitie);
        afiseaza_tabla(tabla);

        if (verifica_castig(tabla)) {
            printf("FELICITARI! Jucatorul cu simbolul %c a castigat!\n", simbol_curent);
            return 0; // Oprim programul aici
    }
    
    }
    return 0;
}