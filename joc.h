#ifndef JOC_H
#define JOC_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
// Culori ANSI pentru terminal
#define CULOARE_RESET   "\033[0m"
#define CULOARE_ROSU    "\033[1;31m"  // Pentru X
#define CULOARE_ALBASTRU "\033[1;34m" // Pentru 0
#define CULOARE_VERDE    "\033[1;32m" // Pentru mesaje de succes/castig
#define CULOARE_GALBEN   "\033[1;33m" // Pentru cifrele tablei
void curata_ecran();
void afiseaza_tabla(char celule[]);
int marcheaza_casuta(char celule[], int pozitie, char simbol);
int verifica_castig(char celule[]);
int mutare_calculator(char celule[]);

#endif