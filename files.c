#include "files.h"

void saveFile(){
    char pergunta[200];
    char r1[50];
    char r2[50];
    char r3[50];
    char r4[50];
    int rcerta;

    printf(" Pergunta: "); gets(pergunta);
    printf(" Resposta1: "); gets(r1);
    printf(" Resposta2: "); gets(r2);
    printf(" Resposta3: "); gets(r2);
    printf(" Resposta4: "); gets(r2);
    printf(" Resposta certa: "); scanf("%d", &rcerta);

    FILE *ficheiro;
    ficheiro= fopen("perguntasOrdem.txt","a+");

    fprintf(ficheiro, "%s;%s;%s;%s;%ddde\n", pergunta, r1 ,r2 ,r3 ,r4 ,rcerta);
}

