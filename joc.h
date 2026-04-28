#ifndef JOC_H
#define JOC_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void curata_ecran();
void afiseaza_tabla(char celule[]);
int marcheaza_casuta(char celule[], int pozitie, char simbol);
int verifica_castig(char celule[]);

#endif