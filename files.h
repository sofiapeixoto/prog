
#ifndef FILES_H
#define FILES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
        char pergunta[300];
        char r1[100];
        char r2[100];
        char r3[100];
        int rcerta;
    }PerguntasOrdem;
    
void meterPerguntaOrdem();
int lerPerguntasOrdem();
void baralharPerguntasOrdem ();
void entraradmin();
#endif //TRABALHO_PRATICO_FILES_H
