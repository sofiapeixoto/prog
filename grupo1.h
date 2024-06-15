
#ifndef GRUPO1_H
#define GRUPO1_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char pergunta[300];
    char r1[100];
    char r2[100];
    char r3[100];
    char r4[100];
    int rcerta;
} Perguntas1;

int lerPerguntas1(Perguntas1 perguntas1[]);
void baralharPerguntas1(Perguntas1 perguntas1[], int totalperguntas);
void meterPerguntas1();

#endif // GRUPO1_H
