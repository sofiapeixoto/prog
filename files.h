
#ifndef FILES_H
#define FILES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char pergunta[300];
    char r1[100];
    char r2[100];
    char r3[100];
    int rcerta;
} PerguntasOrdem;

void meterPerguntaOrdem();
int lerPerguntasOrdem(PerguntasOrdem perguntas[]);
void baralharPerguntasOrdem(PerguntasOrdem perguntas[], int totalperguntas);
void entraradmin();

#endif // FILES_H

