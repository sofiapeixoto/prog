#include "files.h"

void saveFile(){
    char pergunta[300];
    char r1, r2, r3;
    int rcerta;
    
    printf("Pergunta: "); gets(pergunta);
    printf("Resposta1: "); gets(r1);
    printf("Resposta2: "); gets(r2);
    printf("Resposta3: "); gets(r3);
    printf("Resposta certa: "); scanf("%d", &rcerta);
    
FILE *ficheirordem;
    ficheirordem= fopen("perguntasordem.txt","a+");
    fprintf(ficheirordem, "%s;%s;%s;%s;%d\n", pergunta, r1 ,r2 ,r3 ,rcerta);
    fclose(ficheirordem);
}

