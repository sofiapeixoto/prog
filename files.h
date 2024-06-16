
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
    char r4[100];
    int rcerta;
} Perguntas;

typedef struct {
    char pergunta[300];
    char r1[100];
    char r2[100];
    char r3[100];
    int rcerta;
} PerguntasOrdem;

typedef struct {
    int pontuacao;
    char sigla[10];
    char nome[50];
} RANKING;

/* PERGUNTAS NORMAIS */
int lerPerguntas(Perguntas perguntas[]);
void baralharPerguntas(Perguntas perguntas[], int totalperguntas);
void meterPerguntas();

/* PERGUNTAS DE ORDEM */
int lerPerguntasOrdem(PerguntasOrdem perguntas[]);
void baralharPerguntasOrdem(PerguntasOrdem perguntas[], int totalperguntas);
void meterPerguntaOrdem();

/*RANKING*/
void guardarPontuacao(char nome[], char sigla[], int pontuacao);
int lerPontuacao(RANKING utilizador[]);
void bubbleSortDescending(RANKING rankings[], int n);
void mostrarRanking(RANKING rankings[], int totalutilizadores);
#endif // FILES_H

