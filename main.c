#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
// functie pentru a curata ecranul 
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

    return 0;
}