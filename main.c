#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "joc.h"

int main() {
    srand(time(NULL)); // Initializam generatorul de numere aleatoare pentru mutarile calculatorului
    // initializam tabla cu cifrele 1-9 pentru a ghida jucatorul
    char tabla[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int optiune_meniu;

    printf("==============================\n");
    printf("   BINE AI VENIT LA X SI 0    \n");
    printf("==============================\n\n");
    printf("1. Jucator vs Jucator (1v1)\n");
    printf("2. Jucator vs Calculator (vs PC)\n");
    printf("3. Iesire\n");
    printf("-----------------------------------------\n");
    
    do {
        printf("Alege o optiune (1-3): ");
        if (scanf("%d", &optiune_meniu) != 1) {
            while(getchar() != '\n'); 
            continue;
        }
    } while (optiune_meniu < 1 || optiune_meniu > 3);

    if (optiune_meniu == 3) {
        printf("La revedere!\n");
        return 0;
    }

    curata_ecran();
    if (optiune_meniu == 1) {
    char jucator1, jucator2;
    printf("--- MODUL: JUCATOR VS JUCATOR ---\n\n");
       
    
    // alegerea simbolului
    do {
        printf("Jucator 1, alege simbolul (X sau 0): ");
        scanf(" %c", &jucator1);
        jucator1 = toupper(jucator1); 
    } while (jucator1 != 'X' && jucator1 != '0');
    jucator2 = (jucator1 == 'X') ? '0' : 'X';
    curata_ecran();

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
            printf(CULOARE_VERDE "FELICITARI! Jucatorul cu simbolul %c a castigat!\n" CULOARE_RESET, simbol_curent);
            return 0; // Oprim programul aici
        }else if (runda == 8) {
            printf(CULOARE_ROSU "JOC TERMINAT! Este o remiza!\n" CULOARE_RESET);
        }
    
    }
}else if (optiune_meniu == 2) 
{
    char jucator, calculator;
    int runda, pozitie, optiune_meniu;
    char simbol_curent;

    printf("--- MODUL: JUCATOR VS CALCULATOR ---\n\n");
    do {
        printf("Alege simbolul tau (X sau 0): ");
            scanf(" %c", &jucator);
            jucator = toupper(jucator); 
    } while (jucator != 'X' && jucator != '0');

    calculator = (jucator == 'X') ? '0' : 'X';

    curata_ecran();
    printf("Configuratie stabilita: Tu (%c) vs PC (%c)\n", jucator, calculator);
    afiseaza_tabla(tabla);

    for (runda = 0; runda < 9; runda++) {
        // Randul jucatorului (numere pare)
        if (runda % 2 == 0) {
                simbol_curent = jucator;
                int succes = 0;
                while (!succes) {
                    printf("Randul tau (%c). Alege pozitia: ", simbol_curent);
                    if (scanf("%d", &pozitie) != 1) {
                        while(getchar() != '\n'); 
                        continue;
                    }
                    succes = marcheaza_casuta(tabla, pozitie, simbol_curent);
                    if (!succes) {
                        printf("Pozitie invalida sau ocupata!\n");
                    }
                }
            } 
        // Randul calculatorului (numere impare)
        else {
                simbol_curent = calculator;
                printf("Calculatorul alege o pozitie...\n");
                
                pozitie = mutare_calculator(tabla);
                marcheaza_casuta(tabla, pozitie, simbol_curent);
            }

        curata_ecran();
        printf("Ultima mutare: %s a pus %c la pozitia %d\n", 
               (simbol_curent == jucator) ? "Tu" : "PC", simbol_curent, pozitie);
        afiseaza_tabla(tabla);

            // Verificam daca s-a castigat meciul
        if (verifica_castig(tabla)) {
            if (simbol_curent == jucator) {
                printf(CULOARE_VERDE "FELICITARI! Ai castigat!\n" CULOARE_RESET);
                } else {
                    printf(CULOARE_ROSU "Ai pierdut! A castigat calculatorul.\n" CULOARE_RESET);
                }
            return 0;
        } else if (runda == 8) {
            printf(CULOARE_ROSU "JOC TERMINAT! Este o remiza!\n" CULOARE_RESET);
        }

}}
    return 0;
}