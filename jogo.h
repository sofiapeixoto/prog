
#ifndef TRABALHO_PRATICO_JOGO_H
#define TRABALHO_PRATICO_JOGO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "files.h"
#include "menus.h"

void mostrarPerguntas(Perguntas pergunta);
void mostrarPerguntasOrdem (PerguntasOrdem perguntas);
int lerResposta(Perguntas pergunta, int *numcertas);
int lerResposta1(Perguntas pergunta,int *numcertas);
int lerResposta2(PerguntasOrdem perguntas, int *numcertas);
int jaRespondida(int id, int perguntasRespondidas[]);
int grupo1(int *numrespondidas, int *numperguntas,int *numcertas, Perguntas perguntas[], int perguntasRespondidas[], int totalperguntas);
int grupo2(int *numrespondidas, int *numperguntas,int *numcertas, Perguntas perguntas[], int perguntasRespondidas[], int totalperguntas);
int grupo3(int *numrespondidas, int *numperguntas,int *numcertas, PerguntasOrdem perguntas[], int perguntasRespondidas[], int totalperguntas);
int jogo(int *numperguntas, int *numrespondidas, int *numcertas);

#endif //TRABALHO_PRATICO_JOGO_H
